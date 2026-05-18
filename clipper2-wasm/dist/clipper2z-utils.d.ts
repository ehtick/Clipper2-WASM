/// <reference types="emscripten" />
export interface Clipper2ZUtilsFactoryFunction extends EmscriptenModuleFactory<MainModule & EmscriptenModule> { }

export interface FillRuleValue<T extends number> {
  value: T;
}
export type FillRule = FillRuleValue<0>|FillRuleValue<1>|FillRuleValue<2>|FillRuleValue<3>;

export interface SvgReader {
  paths: PathsD;
  delete(): void;
}

export interface SvgWriter {
  FillRule(): FillRule;
  Clear(): void;
  SaveToFile(filename: ArrayBuffer|Uint8Array|Uint8ClampedArray|Int8Array|string, maxWidth: number, maxHeight: number, margin: number): boolean;
  delete(): void;
}

export interface PointD {
  z: bigint;
  x: number;
  y: number;
  SetZ(z: bigint): void;
  delete(): void;
}

export interface PathD {
  clear(): void;
  push_back(point: PointD): void;
  size(): number;
  get(index: number): PointD;
  view(): Float64Array;
  assign(coordinates: Float64Array): void;
  delete(): void;
}

export interface Path64 {
  clear(): void;
  push_back(point: Point64): void;
  size(): number;
  get(index: number): Point64;
  delete(): void;
}

export interface Paths64 {
  clear(): void;
  push_back(path: Path64): void;
  size(): number;
  get(index: number): Path64;
  delete(): void;
}

export interface PathsD {
  clear(): void;
  push_back(path: PathD): void;
  size(): number;
  get(index: number): PathD;
  delete(): void;
}

export interface Point64 {
  x: bigint;
  y: bigint;
  z: bigint;
  SetZ(z: bigint): void;
  delete(): void;
}

export interface MainModule {
  FillRule: {EvenOdd: FillRuleValue<0>, NonZero: FillRuleValue<1>, Positive: FillRuleValue<2>, Negative: FillRuleValue<3>};
  SvgReader: {new(filename: string): SvgReader};
  SvgWriter: {new(): SvgWriter};
  PointD: {new(x: number, y: number, z: number): PointD};
  PathD: {new(): PathD};
  PathsD: {new(): PathsD};
  Point64: {new(x: bigint, y: bigint, z: bigint): Point64};
  SvgAddSolution(writer: SvgWriter, solution: PathsD, fillRule: FillRule, isClosed: boolean): void;
  PathDToPath64(pathD: PathD): Path64;
  Path64ToPathD(path64: Path64): PathD;
  Paths64ToPathsD(paths64: Paths64): PathsD;
  PathsDToPaths64(pathsD: PathsD): Paths64;
}
