# Chapter III Exercise 00: Aaaaand... OPEN!
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, ClapTrap.{h, hpp}, ClapTrap.cpp
- Forbidden functions : None
まず、クラスを実装するんだ! なんて斬新なんだ
クラス名はClapTrapとし、以下のプライベート属性を括弧内に指定した値に初期化する。
•Name, これは、コンストラクタのパラメータとして渡されます。
•Hit points (10), ClapTrapの健康状態を表す
•Energy points (10)
•Attack damage (0)
ClapTrapがよりリアルに見えるように、以下のパブリックメンバー関数を追加します。
•void attack(const std::string& target);
•void takeDamage(unsigned int amount);
•void beRepaired(unsigned int amount);
クラップトラックが攻撃するとき、その対象は＜攻撃ダメージ＞のヒットポイントを失う。
クラップトラックが自身を修復すると、それは＜量＞のヒット・ポイントを取り戻す。攻撃と修理にはそれぞれ1点のエネルギーが必要です。もちろん、ヒットポイントもエネルギーポイントも残っていなければ、何もすることはできません。
これらのメンバー関数のすべてで、何が起こったかを表すメッセージを表示しなければならない。たとえば、attack()関数は次のような表示をします（もちろん、角括弧は抜きで）。
ClapTrap <名前> は <ターゲット> を攻撃し、<ダメージ> ポイントのダメージを与えます!
コンストラクタとデストラクタは、それらが呼び出されたことが簡単にわかるように、メッセージも表示しなければなりません。
あなたのコードが期待通りに動作することを確認するために、独自のテストを実装して提出しましょう。

# Chapter IV Exercise 01: Serena, my love!
- Turn-in directory : ex01/
- Files to turn in : Files from previous exercise + ScavTrap.{h, hpp}, ScavTrap.cpp
- Forbidden functions : None
クラップトラップはいくらあっても足りないので、今度は派生ロボットを作ります。
ScavTrapと名付け、Clap-Trapのコンストラクタとデストラクタを継承することにします。
トラップです。ただし、コンストラクタ、デストラクタ、attack()は異なるメッセージを表示します。
結局のところ、ClapTrapは自分の個性を自覚しているのです。
適切なコンストラクタとデストラクタの連鎖がテストで示されなければならないことに注意してください。
ScavTrapが作られると、プログラムはClapTrapを作ることから始めます。破壊は逆の順序で行われます。なぜか？
ScavTrapはClapTrapの属性を使用し（結果的にClapTrapを更新する）、それらを初期化しなければならない。
•Name, これは、コンストラクタのパラメータとして渡されます。
•Hit points (100), ClapTrapの健康状態を表す
•Energy points (50)
•Attack damage (20)
ScavTrapはまた、それ自身の特別な能力:void guardGate()を持つことになります。
このメンバ関数は、ScavTrap がゲートキーパモードになったことを知らせるメッセージを表示します。
あなたのプログラムにもっとテストを追加することを忘れないでください。

# Chapter V Exercise 02: Repetitive work
- Turn-in directory : ex02/
- Files to turn in : Files from previous exercises + FragTrap.{h, hpp}, FragTrap.cpp
- Forbidden functions : None
ClapTrapを作るのが面倒になってきたのではないでしょうか。
さて、ClapTrapを継承したFragTrapクラスを実装してみましょう。これは
ScavTrapとよく似ています。しかし、建設と破壊のメッセージは違うものにしなければなりません。適切な建設と破壊の連鎖を、テストで示さなければなりません。FragTrapが作られると、プログラムはClapTrapを作ることから始めます。破壊は逆の順序で行われます。
属性については同じことですが、今回は異なる値で行います。
•Name, which is passed as parameter to a constructor
•Hit points (100), represent the health of the ClapTrap
•Energy points (100)
•Attack damage (30)
FragTrapは特別な能力も持っています:void highFivesGuys(void)。
このメンバ関数は、標準出力に肯定的なハイタッチの要求を表示します。
もう一度、プログラムにテストを追加してください。

# Chapter VI Exercise 03: Now it’s weird!
- Turn-in directory : ex03/
- Files to turn in : Files from previous exercises + DiamondTrap.{h, hpp}, DiamondTrap.cpp
- Forbidden functions : None
この演習では、半分FragTrap、半分ScavTrapのClapTrapというモンスターを作成します。
ScavTrapです。DiamondTrapという名前で、FragTrapとScavTrapの両方を継承している。
ScavTrapの両方を継承する。これはとてもリスキーだ！
DiamondTrapクラスはname private属性を持っています。この属性には、ClapTrap基底クラスの変数名と全く同じ変数名（ここではロボットの名前について話していません）を与えてください。
もっとわかりやすくするために、二つの例を挙げよう。
ClapTrapの変数がnameの場合、DiamondTrapの変数と同じnameを与える。
ClapTrapの変数が_nameなら、DiamondTrapの変数に_nameを与える。
その属性とメンバー関数は、どちらかの親クラスから選ばれる。
•Name, which is passed as parameter to a constructor
•ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
•Hit points (FragTrap)
•Energy points (ScavTrap)
•Attack damage (FragTrap)
•attack() (Scavtrap)
親クラスの特別な機能に加えて、DiamondTrapは、独自の特別な機能を持つ。
このメンバ関数は、自分の名前とClapTrapの名前の両方を表示します。
もちろん、DiamondTrapのClapTrapサブオブジェクトは、一度だけ作成されます。そう、仕掛けがあるのです。
もう一度、プログラムにテストを追加してください。
  Wshadowと-Wno-shadowというコンパイラフラグをご存知ですか？