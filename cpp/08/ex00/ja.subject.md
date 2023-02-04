# 第III章 モジュール固有の規則
このモジュールでは、標準コンテナや標準アルゴリズムがなくても、演習を解くことができることに気づくでしょう。
しかし、それらを使うことこそ、このモジュールの目標なのです。STLを使うことは許されています。そう、コンテナ（vector/list/map/など）とアルゴリズム（ヘッダ<algorithm>で定義）を使うことができるのです。しかも、できる限り使うべきです。したがって、適切な場所であればどこでもそれらを適用するように最善を尽くしましょう。
そうしないと、たとえあなたのコードが期待通りに動作したとしても、非常に悪い評価を受けることになります。怠け者にならないでください。
テンプレートは通常通りヘッダーファイルで定義することができます。あるいは、テンプレートの宣言をヘッダーファイルで書き、その実装を.tppファイルで書いても構いません。いずれにせよ、ヘッダーファイルは必須で、.tppファイルは任意です。

# Chapter IV Exercise 00: Easy find
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, easyfind.{h, hpp} and optional file: easyfind.tpp
- Forbidden functions : None
最初の簡単な練習は正しい足取りでスタートする方法です。
型Tを受け入れる関数テンプレートeasyfindを書きましょう。それは2つのパラメータを取ります。
最初のパラメータは T 型で、2 番目のパラメータは整数です。
T が整数のコンテナであると仮定して、この関数は最初のパラメータで2番目のパラメータの最初の出現を見つけなければなりません。
もし見つからなかったら、例外を投げるか、任意のエラー値を返せばよい。もしインスピレーションが必要なら、標準的なコンテナがどのように動作するかを分析してみてください。
もちろん、すべてが期待通りに動作することを確認するために、独自のテストを実装して回してください。
連想コンテナを扱う必要はありません。

# Chapter V Exercise 01: Span
- Turn-in directory : ex01/
- Files to turn in : Makefile, main.cpp, Span.{h, hpp}, Span.cpp
- Forbidden functions : None
最大N個の整数を格納できるSpanクラスを開発せよ。N は unsigned int 変数で、コンストラクタに渡される唯一のパラメータとなる。
このクラスはaddNumber()というメンバ関数を持ち、Spanに1つの数値を追加する。これは、Spanを埋めるために使用されます。すでにN個の要素が格納されている場合に、新しい要素を追加しようとすると、例外が発生するはずです。
次に、2つのメンバ関数、shortestSpan() と longestSpan() を実装する。
それぞれ、格納されているすべての数値の間の最短スパン、最長スパン（距離でもよい）を求め、それを返します。もし、格納されている数が1つもないか、1つしかない場合は、スパンを見つけることができません。したがって、例外を投げる。
もちろん、あなた自身のテストを書いて、以下のテストよりもずっと綿密なものになるでしょう。少なくとも1万個以上の数でテストしてください。もっと多ければなおよい。
Running this code:
```cpp
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
```
Should output:
```
$> ./ex01
2
14
$>
```
最後になりますが、イテレータの範囲を使ってSpanを埋めることができれば素晴らしいことです。
addNumber() を何度も呼び出すのはとても面倒です。一回の呼び出しで多くの数値をSpanに追加できるようなメンバ関数を実装してください。
ヒントがない場合は、コンテナについて勉強してください。いくつかのメンバ関数は、コンテナに一連の要素を追加するために、イテレータの範囲を取ります。

# Chapter VI Exercise 02: Mutated abomination
- Turn-in directory : ex02/
- Files to turn in : Makefile, main.cpp, MutantStack.{h, hpp} and optional file: MutantStack.tpp
- Forbidden functions : None
さて、そろそろもっと本格的な話に移ろうか。何か変なものを開発しましょう。
std::stack コンテナはとてもいいものです。しかし残念なことに、これは反復可能でない唯一の STL コンテナのひとつです。それは残念なことです。
しかし、なぜそれを受け入れなければならないのだろうか？特に、オリジナルのスタックを自由に加工して、足りない機能を作ることができるのであれば。
この不正を修復するためには、std::stack コンテナをイテラブルにする必要があります。
MutantStack クラスを書きましょう。このクラスは std::stack の形で実装されます。
そのクラスはスタックのメンバー関数をすべて提供し、さらにイテレータという追加機能を提供します。
もちろん、すべてが期待通りに動作することを確認するために、 自分でテストを書いて提出することになります。
以下にテスト例を示します。
```cpp
int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
```
一回目はMutantStackで実行し、二回目はMutantStackを例えばstd::listに置き換えて実行すると、2つの出力は同じになるはずです。
MutantStack を例えば std::list に置き換えて二度目に実行すると、二つの出力は同じになるはずです。もちろん、別のコンテナをテストする場合は、以下のコードを対応するメンバ関数で更新してください（push()はpush_back()になることがあります）。