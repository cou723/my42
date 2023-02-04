# Chapter III Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
- Forbidden functions : None
例外クラスは、正統派正典形式で設計される必要はないことに注意してください。しかし、他のすべてのクラスはそうしなければなりません。

オフィス、廊下、帳票、待ち行列など、人工的な悪夢をデザインしてみよう。
面白そうですか？いいえ？残念でしたね。
まず、この巨大な官僚機構の最も小さな歯車である官僚から始めましょう。
ビューロクラットは次のようなものを持っていなければならない。
- A constant name.
- And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
無効な等級を使用してビューロクラットのインスタンスを作成しようとすると、例外が発生します。
Bureaucrat::GradeTooHighException または Bureaucrat::GradeTooLowException のどちらかの例外が発生します。

これらの属性のゲッターは、getName() と getGrade() を用意します。また、官僚の等級を増減させるための2つのメンバ関数を実装します。等級が範囲外である場合、それらの両方はコンストラクタと同じ例外を投げるでしょう。
覚えておいてください。等級 1 が最高で、150 が最低なので、等級 3 をインクリメントすると、官僚は等級 2 になるはずです。
投げられた例外は try ブロックと catch ブロックを使ってキャッチ可能でなければなりません。
```cpp
try
{
/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
/* handle exception */
}
```
挿入（"）演算子のオーバーロードを実装して、次のような表示をすることになります。
(角括弧なし) を表示します。
<name>, bureaucrat grade <grade>.
いつものように、期待通りに動作することを証明するために、いくつかのテストを提出します。

# Chapter IV Exercise 01: Form up, maggots!
- Turn-in directory : ex01/
- Files to turn in : Files from previous exercise + Form.{h, hpp}, Form.cpp
- Forbidden functions : None
さて、官僚ができたからには、何か仕事を与えよう。フォームの束に記入すること以上に良い活動があるだろうか？
そこで、Formクラスを作りましょう。これには
•A constant name.
•A boolean indicating whether it is signed (at construction, it’s not).
•A constant grade required to sign it.
•And a constant grade required to execute it.
これらの属性はすべて私的なものであり、保護されるものではありません。
フォームの評点はビューロクラットに適用されるのと同じルールに従います。従って、フォームのグレードが範囲外である場合、以下の例外がスローされます。
Form::GradeTooHighException and Form::GradeTooLowException.
前と同じように、すべての属性のゲッターと、フォームのすべての情報を表示する挿入（"）演算子のオーバーロードを記述してください。

Bureaucrat をパラメータとして受け取る beSigned() メンバ関数もフォームに追加する。これは、ビューロクラットの等級が十分に高い (必要な等級より高い、または同等) 場合に、フォームの状態を署名済みに変更します。等級 1 は等級 2 よりも高いことを忘れないように。
評点が低すぎる場合は Form::GradeTooLowException を投げる。
最後に、Bureaucrat に signForm() メンバ関数を追加します。フォームが署名された場合、次のように表示されます。
<bureaucrat> signed <form>
そうでない場合は、次のように表示されます。
<bureaucrat> couldn’t sign <form> because <reason>.
期待通りに動作することを確認するために、いくつかのテストを実施し、提出する。

# Chapter V Exercise 02: No, you need form 28B, not 28C...
- Turn-in directory : ex02/
- Files to turn in : Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp], Bureaucrat.cpp + AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp], + RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp]
- Forbidden functions : None
基本的なフォームができたので、次は実際に何かをするフォームをいくつか作ってみましょう。
どのような場合でも、基底クラス Form は抽象クラスでなければならないので、 AForm という名前に変更します。フォームの属性はプライベートである必要があり、それらは基底クラスにあることに留意してください。
次の具象クラスを追加します。
•ShrubberyCreationForm: Required grades: sign 145, exec 137
作業ディレクトリに<target>_shrubberyというファイルを作成し、その中にASCIIツリーを書き込む。
•RobotomyRequestForm: Required grades: sign 72, exec 45
ドリルで穴を開ける音がする。その後、<target>が50%の確率でロボット化成功したことを知らせる。そうでなければ、ロボトミーに失敗したと知らせる。
•PresidentialPardonForm: Required grades: sign 25, exec 5
<target> が Zaphod Beeblebrox によって恩赦されたことを通知する。
これらはすべてコンストラクタでパラメータをひとつだけ受け取ります：フォームのターゲットです。例えば、自宅に低木を植えたい場合は "home" とする。

さて、ベースフォームに execute(Bureaucrat const & executor) const メンバ関数を追加し、 具象クラスのフォームのアクションを実行する関数を実装します。フォームが署名されていることと、フォームを実行しようとする官僚の等級が十分高いことを確認する必要があります。そうでない場合は、適切な例外を投げる。
すべての具象クラスで要件を確認するか、ベースクラスで確認するか（それから別の関数を呼び出してフォームを実行するか）、それはあなた次第です。しかし、どちらかの方法の方がきれいです。
最後に、Bureaucrat に executeForm(Form const & form) メンバ関数を追加してください。これはフォームの実行を試みなければなりません。もし成功したら、次のようなものをプリントする。
<bureaucrat> executed <form>
そうでない場合は、明示的なエラーメッセージを表示する。
すべてが期待通りに動くことを確認するために、いくつかのテストを実装し、提出する。

# Chapter VI Exercise 03: At least this beats coffee-making
- Turn-in directory : ex03/
- Files to turn in : Files from previous exercises + Intern.{h, hpp}, Intern.cpp
- Forbidden functions : None
書類の記入だけでも十分迷惑なのに、官僚に一日中これをやらせるのは酷な話です。幸いなことに、インターンは存在します。この演習では、インターンクラスを実装する必要があります。インターンには名前も等級も固有の特性もありません。官僚が気にするのは、彼らが仕事をすることだけです。
しかし、インターンには、makeForm() 関数という重要な能力があります。この関数は2つの文字列を受け取る。最初の文字列はフォームの名前、2番目の文字列はフォームのターゲットである。この関数はフォームオブジェクトへのポインタを返し、そのオブジェクトの名前はパラメータとして渡されたものです。
このとき、次のようなメッセージが表示されます。
Intern creates <form>
パラメータとして渡されたフォーム名が存在しない場合、明示的なエラーメッセージを表示します。

if/elseif/elseの森を使うような、読めない、醜い解決策は避けなければなりません。このようなものは、評価プロセスで受け入れられません。あなたはもうPiscine(プール)の中にいるのではありません。いつものように、すべてが期待通りに動くかどうかテストしなければなりません。
例えば、以下のコードは "Bender" をターゲットとした RobotomyRequestForm を作成します。
```cpp
{
Intern someRandomIntern;
Form* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```