[![npm version](https://badge.fury.io/js/clipper2-wasm.svg)](https://badge.fury.io/js/clipper2-wasm)
# Clipper2 WASM

The <b>Clipper2</b> library performs **intersection**, **union**, **difference** and **XOR** boolean operations on both simple and complex polygons. It also performs polygon offsetting and constrained Delaunay triangulation.

## Documentation:
For Clipper2 documentation please see the [Extensive HTML documentation](http://www.angusj.com/clipper2/Docs/Overview.htm)

## Live examples:
- [Basic](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/basic.html)
- [SVG-Tools](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/svg-tools.html)
- [Rect Clip](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/rectclip.html)
- [Offset](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/offset.html)
- [Minkowski](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/minkowski.html)
- [Rect Clip Lines](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/rectclip-lines.html)
- [Triangulation](https://eriksom.github.io/Clipper2-WASM/clipper2-wasm/examples/es/triangulation.html)

## Download lib
ES6: https://github.com/ErikSom/Clipper2-WASM/tree/main/CPP/clipper2-wasm/dist/es/

UMD: https://github.com/ErikSom/Clipper2-WASM/tree/main/CPP/clipper2-wasm/dist/umd/

## Usage:
For ES6 see the examples here:
https://github.com/ErikSom/Clipper2-WASM/tree/main/CPP/clipper2-wasm/examples/es

For UMD see the examples here:
https://github.com/ErikSom/Clipper2-WASM/tree/main/CPP/clipper2-wasm/examples/umd

## Typescript example:
```javascript
import { Clipper2ZFactoryFunction, MainModule } from 'clipper2-wasm/dist/clipper2z';
import * as _Clipper2ZFactory from 'clipper2-wasm/dist/umd/clipper2z';

const Clipper2ZFactory: Clipper2ZFactoryFunction = _Clipper2ZFactory;

Clipper2ZFactory({
	locateFile: () => {
		return 'path/to/your/clipper2z.wasm'
	},
}).then((Clipper2Z: MainModule) => {
	console.log('Clipper2Z', Clipper2Z);
})
```

## Benchmark vs Clipper1 WASM: (Apple M2 Pro)
Clipper1 WASM repository: https://github.com/xaviergonz/js-angusj-clipper
<img width="1008" height="416" alt="image" src="https://github.com/user-attachments/assets/59543ebe-e501-46f6-b1cc-c2f9f32d5b18" />

See implementation: https://github.com/ErikSom/Clipper2-WASM/tree/main/clipper2-wasm/examples/benchmark

Made possible by:
https://github.com/AngusJohnson/Clipper2

Huge thanks to [@Birch-san](https://www.github.com/Birch-san) with an outstanding wasm port example:
https://github.com/Birch-san/box2d-wasm/
