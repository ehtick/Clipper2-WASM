#include "clipper2/clipper.core.h"
#include "clipper.svg.h"
#include "clipper.svg.utils.h"
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;
using namespace Clipper2Lib;

#ifdef USINGZ
static_assert(sizeof(PointD) == 3 * sizeof(double),
              "PathD_view/assign require USINGZ layout: PointD == {x, y, z}");

val PathD_view(const PathD& path) {
    return val(typed_memory_view(path.size() * 3,
                                 reinterpret_cast<const double*>(path.data())));
}

void PathD_assign(PathD& path, val jsArray) {
    const unsigned len = jsArray["length"].as<unsigned>();
    if (len % 3 != 0) {
        throw std::runtime_error("PathD.assign: array length must be a multiple of 3");
    }
    const unsigned n = len / 3;
    path.resize(n);
    if (n > 0) {
        val view(typed_memory_view(n * 3, reinterpret_cast<double*>(path.data())));
        view.call<void>("set", jsArray);
    }
}
#endif // USINGZ

EMSCRIPTEN_BINDINGS(clipper_module) {
    enum_<FillRule>("FillRule")
        .value("EvenOdd", FillRule::EvenOdd)
        .value("NonZero", FillRule::NonZero)
        .value("Positive", FillRule::Positive)
        .value("Negative", FillRule::Negative);

	class_<SvgReader>("SvgReader")
    .constructor<std::string>()
		.property("paths", &SvgReader::paths);

	class_<SvgWriter>("SvgWriter")
        .constructor<>()
        .function("Clear", &SvgWriter::Clear)
        .function("FillRule", &SvgWriter::Fill_Rule)
        .function("SaveToFile(filename, maxWidth, maxHeight, margin)", &SvgWriter::SaveToFile);

	// SvgAddSolution
	function("SvgAddSolution(writer, solution, fillRule, isClosed)", select_overload<void(SvgWriter&, const PathsD&, FillRule, bool)>(&SvgAddSolution));

	#ifdef USINGZ
	class_<PointD>("PointD")
		.constructor<double, double, double>()
		.property("x", &PointD::x)
		.property("y", &PointD::y)
		.property("z", &PointD::z)
		.function("SetZ(z)", &PointD::SetZ);
	#else
	class_<PointD>("PointD")
		.constructor<double, double>()
		.property("x", &PointD::x)
		.property("y", &PointD::y);
	#endif

	class_<PathD>("PathD")
		.constructor<>()
		.function("size", &PathD::size)
		.function("clear", &PathD::clear)
		.function("push_back(point)", select_overload<void(const PointD&)>(&PathD::push_back))
		.function("get(index)", select_overload<PointD&(size_t)>(&PathD::operator[]), allow_raw_pointers())
#ifdef USINGZ
		.function("view", &PathD_view)
		.function("assign(coordinates)", &PathD_assign)
#endif
		;

	class_<PathsD>("PathsD")
		.constructor<>()
		.function("size", &PathsD::size)
		.function("clear", &PathsD::clear)
		.function("push_back(path)", select_overload<void(const PathD&)>(&PathsD::push_back))
		.function("get(index)", select_overload<PathD&(size_t)>(&PathsD::operator[]), allow_raw_pointers());

	// Point64 bindings (for now only support USINGZ=ON)
	#ifdef USINGZ
	class_<Point64>("Point64")
		.constructor<int64_t, int64_t, int64_t>()
		.property("x", &Point64::x)
		.property("y", &Point64::y)
		.property("z", &Point64::z)
		.function("SetZ(z)", &Point64::SetZ);
	#else
	class_<Point64>("Point64")
		.constructor<int64_t, int64_t>()
		.property("x", &Point64::x)
		.property("y", &Point64::y);
	#endif
}
