第一章
はじめに
C++は、Bjarne StroustrupがC言語の拡張として作った汎用プログラミング言語であり、「C with Classes」（出典：Wikipedia）である。
このモジュールの目標は、オブジェクト指向プログラミングを紹介することです。
これは、あなたのC++の旅の出発点となるでしょう。OOPを学ぶには多くの言語が推奨されます。私たちは、あなたの古い友人であるCから派生したC++を選択することにしました。
C++は複雑な言語なので、物事を単純にするために、あなたのコードはC++98標準に準拠することになります。
私たちは、現代のC++が多くの面で大きく異なっていることを認識しています。ですから、もしあなたが熟練したC++開発者になりたいのであれば、42コモンコアの後にさらに進むのはあなた次第なのです

## 第二章
### 一般規則
#### コンパイル
- c++とフラグ-Wall -Wextra -Werrorを使用してコードをコンパイルしてください。
- std=c++98フラグを追加しても、あなたのコードはコンパイルされるはずです。
#### 書式と命名規則
- 演習用ディレクトリの名前は次のようになります：ex00, ex01, ... exn
- ファイル名、クラス名、関数名、メンバ関数名、属性名は、ガイドラインにしたがって命名してください。
- クラス名はUpperCamelCaseで記述してください。クラス名はアッパーキャメルケース（大文字）で記述してください。例えば
例えば、ClassName.hpp/ClassName.h, ClassName.cpp, または ClassName.tpp のように。例えば、レンガの壁を表すクラス "BrickWall "の定義を含むヘッダーファイルは、BrickWall.hppという名前になります。
- 特に指定がない限り、すべての出力メッセージは改行文字で終了し、標準出力に表示されなければなりません。
- さようならノルミネット C++モジュールでは、コーディングスタイルを強制しません。あなたの好きなスタイルに従えばいいのです。しかし、同僚評価者が理解できないコードは、評価できないコードであることを心に留めておいてください。きれいで読みやすいコードを書くために、最善を尽くしてください。
### 許されること／許されないこと
あなたはもうCでコーディングする必要はありません。C++の出番です! したがって
- 標準ライブラリのほとんどすべてを使うことが許されています。したがって、すでに知っていることに固執するのではなく、使い慣れたC関数のC++的なバージョンをできるだけ使うのが賢いやり方でしょう。
- ただし、それ以外の外部ライブラリは使えません。C++11（とその派生形）、Boostライブラリは禁止ということです。以下の関数も禁止です。*printf()、*alloc()、free()。これらを使用した場合、成績は0点、それで終わりです。
- また、using namespace <ns_name> と friend キーワードは明示的に指定されていない限り禁止されています。さもなければ、あなたの成績は-42になります。
- STL はモジュール 08 でのみ使用することが許されています。つまり、以下は禁止事項です。
つまり、コンテナ (vector/list/map/ など) とアルゴリズム (<algorithm> ヘッダを含む必要があるもの) を使用することはできません。さもなければ、あなたの成績は -42 となります。
### いくつかの設計要件
- メモリリークはC++でも発生します。メモリを割り当てるとき（new キーワードを使用する）、メモリリークを回避しなければなりません。
- モジュール02からモジュール08まで、あなたのクラスは、特に明記された場合を除き、正統派の正準形式で設計されていなければなりません。
- ヘッダーファイルに書かれた関数の実装は（関数テンプレートを除いて）、演習では0を意味します。
- ヘッダーファイルの中にある関数の実装は、（関数テンプレートを除いて）演習では0となります。したがって、それらは必要な依存関係をすべて含んでいなければなりません。しかし、インクルードガードを追加することによって、二重インクルードの問題を回避しなければなりません。そうでなければ、あなたの成績は 0 になります。
お読みください
- 必要であれば、いくつかの追加ファイルを追加することができます (つまり、コードを分割するためです)。これらの課題はプログラムによって検証されないので、必須ファイルを提出する限り、自由にやってください。
- 時には、演習のガイドラインは短く見えますが、例題は指示書に明示的に書かれていない要件を示すことがあります。
- 始める前に、各モジュールを完全に読んでください。本当に、そうしてください。
- オーディンによって、トールによって! 頭を使いましょう!
たくさんのクラスを実装する必要があります。これは、あなたがお気に入りのテキストエディタをスクリプト化できるのでない限り、退屈に思えるかもしれません。
演習をこなすには、ある程度の自由が与えられています。
しかし、必須のルールに従い、怠慢にならないようにしましょう。多くの有益な情報を見逃すことになります。理論的な概念については、ためらわずに読んでください。

## 第三章 練習問題00：ブライユインズZ
- 提出先ディレクトリ : ex00/
- 提出するファイル: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, newZombie.cpp、randomChump.cpp。
- 禁止されている関数 なし
まず、Zombieクラスを実装します。文字列のprivate属性nameを持っています。
Zombie クラスにメンバ関数 void announce( void ); を追加する。ゾンビは以下のように自分自身をアナウンスする。
<名前>: BraiiiiinnnzzzZ...
角括弧(<と>)は出力しないようにする。Fooという名前のゾンビの場合、メッセージは次のようになります。
Foo: BraiiiiinnnzzzZ...」となります。
次に、以下の2つの関数を実装します。
- Zombie* newZombie( std::string name );
ゾンビを作成して名前をつけ、それを返すので、関数スコープ外で使用することができます。
- void randomChump( std::string name );
ゾンビを作成し、名前を付けて、ゾンビが自分自身を発表します。
さて、実際のところ、この演習のポイントは何でしょうか？どのような場合にスタックやヒープにゾンビを割り当てるのが良いかを判断する必要があります。
ゾンビは不要になったら破棄しなければなりません。デストラクタは、デバッグのためにゾンビの名前をメッセージとして表示しなければなりません。

## 第四章 演習01 Moar brainz!
- 提出先ディレクトリ : ex01/
- 提出するファイル 提出するファイル : Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, zombieHorde.cpp
- 禁止された関数: なし
ゾンビの大群を作る時間だ!
以下の関数を適切なファイルに実装してください。
Zombie* zombieHorde( int N, std::string name ); 
N 個の Zombie オブジェクトを一度に割り当てる必要がある。次に、ゾンビを初期化し、パラメータとして渡された名前を各ゾンビに与える必要があります。この関数は最初のゾンビへのポインタを返します。
zombieHorde()関数が期待通りに動作することを確認するために、独自のテストを実装してください。
各ゾンビに対して announce() を呼び出してみてください。
すべてのゾンビを削除し、メモリリークをチェックすることを忘れないでください。

## 第五章 練習問題02：HI THIS IS BRAIN
- 提出先ディレクトリ : ex02/
- 提出するファイル Makefile、main.cpp
- 禁止されている関数：なし
以下の内容を含むプログラムを作成しなさい。
- A string variable initialized to "HI THIS IS BRAIN".
- stringPTR: A pointer to the string.
- stringREF: A reference to the string.
あなたのプログラムは、次のことを表示しなければならない。
- 文字列変数のメモリアドレス
- stringPTRのメモリアドレス
- stringREFが保持するメモリアドレス
そして
- 文字列変数の値
- stringPTRが指す値
- stringREFが指す値
以上です。トリックはありません。この演習の目的は、全く新しいと思われる参照を解明することです。ちょっとした違いはありますが、これはアドレス操作というすでにやっていることの別の構文なのです。

## 第六章 演習 03：不要な暴力
Exercise : 03 不要な暴力
- 提出先ディレクトリ : ex03/
- 提出するファイル Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,
hpp}、HumanA.cpp、HumanB.{h, hpp}、HumanB.cpp。
- 禁止されている関数 : なし

Weapon クラスを実装します。
- プライベート属性の型は文字列です。
- typeへのconst参照を返すgetType()メンバ関数。
- パラメータとして渡された新しいものを使って型を設定する setType()メンバ関数。
ここで、2つのクラスを作成します。HumanAとHumanBです。両方とも武器と名前を持っています。また、attack()というメンバ関数があり、（もちろん、角括弧を除いて）これを表示します。
<名前> は <武器の種類> で攻撃します。
HumanAとHumanBは、次の2つの小さな点を除いて、ほとんど同じです。
- HumanAがコンストラクタでWeaponを取るのに対し、HumanBは取りません。
- HumanAはコンストラクタで武器を取りますが、HumanBは取りません。-HumanBは常に武器を持っているとは限りませんが、HumanAは常に武装しています。

実装が正しければ、以下のコードを実行すると、両方のテストケースについて、「粗末なスパイク付きの棍棒」による攻撃と、「他の種類の棍棒」による2回目の攻撃が出力されます。
```cpp
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
    bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
```
メモリリークのチェックを忘れずに。
どのような場合にWeaponへのポインタを使用するのが最適だと思いますか？そしてWeaponへの参照は？なぜでしょうか？この演習を始める前に考えておいてください。


## 第VII章 練習問題04 セドは敗者のためにある
- 提出ディレクトリ : ex04/
- 提出するファイル Makefile, main.cpp, *.cpp, *.{h, hpp}.
- 禁制の関数 : std::string::replace

ファイル名、2つの文字列 s1 と s2 の順に3つのパラメータを受け取るプログラムを作成しなさい。
このプログラムは、ファイル <filename> を開き、その内容を新しいファイル <filename>.replace にコピーし、s1 が現れるたびに s2 に置き換えます。
C のファイル操作関数を使うことは禁じられており、不正行為とみなされます。std::string クラスのメンバ関数は、replace 以外はすべて使用可能です。それらを
を賢く使ってください。
もちろん、予期せぬ入力やエラーに対処してください。プログラムが期待通りに動作することを確認するために、自分でテストを作成して提出する必要があります。

## 第VIII章 演習05：ハール2.0
演習：05 ハール2.0
- 提出先ディレクトリ : ex05/
- 提出するファイル Makefile、main.cpp、Harl.{h, hpp}、Harl.cpp。
- 禁止されている関数 なし

Harlをご存じですか？みんな知ってるよね？でも、Harlがどのようなコメントをするかは、以下のとおりです。レベル別に分類しています。
-DEBUG」レベル。デバッグメッセージは、文脈情報を含んでいます。主に問題の診断に使われる。
例 「7XL-double-cheese-triple-pickle-special-ketchup バーガーにベーコンを追加するのが好きです。本当にそう思う！"
- "INFO "レベル。これらのメッセージは広範な情報を含んでいる。これらは実稼働環境でのプログラム実行をトレースするのに役立つ。
例 "ベーコンを追加すると、もっとお金がかかるなんて信じられません。私のハンバーガーに十分なベーコンを入れていないじゃないか! もしそうなら、もっと要求しないぞ！"
- "WARNING "レベル。警告メッセージは、システムに潜在的な問題があることを示します。
ただし、対処することも無視することも可能です。
例 "私は無料でベーコンを追加してもらうのが当然だと思う。私は何年も通っていますが、あなたは先月から働き始めたばかりです。
- "ERROR "レベル。これらのメッセージは、回復不可能なエラーが発生したことを示します。これは通常、手動での介入を必要とする重大な問題である。
例 例: 「こんなことは受け入れられない! 今すぐマネージャーと話したい。"

ハールを自動化するのですね。いつも同じことを言うので、難しくはないでしょう。以下のプライベートメンバー関数を持つ Harl クラスを作成する必要があります。
-void debug( void );
void debug( void ); -void info( void );
-void warning( void );
-void error( void );
また、Harlには、パラメータとして渡されたレベルに応じて、上記の4つのメンバ関数を呼び出すパブリックメンバ関数があります。
void complain( std::string level );
この演習の目標は、メンバ関数へのポインタを使用することです。これは提案ではありません。Harlは、if/else if/elseの森を使わずに文句を言わなければなりません。それは二度考えません!
Harl がたくさん文句を言うことを示すテストを作成し、提出しなさい。例のコメントを使うことができます。
Harl がたくさん文句を言うことを示すテストを作成し、提出しなさい。題名にある上記のコメント例を使ってもいいですし、自分で選んだコメントを使ってもいいです。

第IX章 練習問題06 ハールフィルタ
演習：06 ハールフィルタ
- 提出先ディレクトリ : ex06/
- 提出するファイル Makefile、main.cpp、Harl.{h, hpp}、Harl.cpp。
- 禁止されている関数 なし
Harl が言うことすべてに注意を払いたくないことがあります。そこで、Harl の発言に耳を傾けたいログのレベルに応じて、Harl の発言をフィルタリングするシステムを実装してください。
4つのレベルのうち1つをパラメータとするプログラムを作成します。このプログラムは、このレベル以上のすべてのメッセージを表示します。例えば
$> ./harlFilter "WARNING"
[ WARNING ]です。
私はベーコンをタダで食べるに値すると思う。
私は何年も通っていますが、あなたは先月からここで働き始めました。
[ ERROR ]
これは受け入れられません、今すぐマネージャーと話したいです。
$> ./harlFilter "今日の疲れは何だろう..."
[ おそらく、取るに足らない問題への愚痴 ]。
Harlに対処する方法はいくつかありますが、最も効果的な方法の1つは、「SWITCH OFF」です。
スイッチを切ることです。
あなたの実行ファイルにharlFilterという名前をつけてください。
この演習では switch ステートメントを使用する必要があり、またおそらくそれを発見するでしょう。
このモジュールは、演習06を行わずに合格することができます。