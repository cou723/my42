# Chapter III Exercise 00: Start with a few functions
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, whatever.{h, hpp}
- Forbidden functions : None
以下の関数テンプレートを実装する。
- swap: 与えられた2つの引数の値を交換する。何も返さない。
- min: 引数で渡された2つの値を比較し、最も小さい値を返します。2つの値が等しい場合は、2番目の値を返す。
- max 引数で渡された2つの値を比較し、最大のものを返します。
2つの値が等しい場合は、2番目の値が返されます。
これらの関数は、どのようなタイプの引数でも呼び出すことができます。唯一の要件は、2つの引数が同じ型であり、すべての比較演算子をサポートしていなければならないことである。
テンプレートはヘッダーファイルで定義されなければならない。

Running the following code:
```cpp
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
```
Should output:
```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

# Chapter IV Exercise 01: Iter
- Turn-in directory : ex01/
- Files to turn in : Makefile, main.cpp, iter.{h, hpp}
- Forbidden functions : None
3つのパラメータを受け取り，何も返さない関数テンプレート iter を実装してください．
- 最初のパラメータは配列のアドレスです．
- 2番目のパラメータは配列の長さです。
- 3番目のパラメータは、配列の各要素に対して呼び出される関数です。
あなたのテストを含む main.cpp ファイルを提出しなさい。テストの実行ファイルを生成するのに十分なコードを用意してください。
iter 関数テンプレートは、任意の型の配列で動作する必要があります。3番目のパラメータは、インスタンス化された関数テンプレートであることができます。

# Chapter V Exercise 02: Array
- Turn-in directory : ex02/
- Files to turn in : Makefile, main.cpp, Array.{h, hpp} and optional file: Array.tpp
- Forbidden functions : None
型Tの要素を含むクラステンプレートArrayを開発し、以下の動作と機能を実装せよ。
- パラメータ無しで構築する。空の配列を作成する．
- unsigned int nをパラメータとする構成．デフォルトで初期化されたn個の要素を持つ配列を作成します．Tip: int * a = new int(); とコンパイルして、*a を表示させてみてください。
- コピーと代入演算子による構築。どちらの場合も、コピーした後に元の配列やそのコピーを変更しても、もう一方の配列に影響を及ぼしてはいけません。
- メモリ確保にはnew[]演算子を使用しなければならない（MUST）。予防的割り当て（事前にメモリを割り当てること）は禁止されています。プログラムは、割り当てられなかったメモリに決してアクセスしてはいけません。
- 要素には添え字演算子でアクセスできます。[ ].
- 演算子で要素にアクセスするとき、そのインデックスが範囲外であれば、std::exception が投げられる。
- メンバ関数 size() は、配列の要素数を返します。この関数はパラメータを持たず、現在のインスタンスを変更してはいけません。
いつものように、すべてが期待通りに動作することを確認し、テストを含む main.cpp ファイルを提出します。
