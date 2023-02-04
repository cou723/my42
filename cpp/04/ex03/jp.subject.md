## Chapter III Exercise 00: Polymorphism
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
- Forbidden functions : None
すべての演習で、可能な限り完全なテストを提供する必要があります。
各クラスのコンストラクタとデストラクタは、特定のメッセージを表示する必要があります。すべてのクラスで同じメッセージを使用しないようにしましょう。
まず、Animal という単純な基底クラスを実装することから始めましょう。このクラスは1つのprotected属性を持っています。
- std::string type;
Animal を継承した Dog クラスを実装する。
Animal を継承した Cat クラスを実装する。
この2つの派生クラスは、その名前によって型フィールドを設定しなければなりません。そして、Dog の型は "Dog" に、Cat の型は "Cat" に初期化されます。
Animalクラスのtypeは空のままでも、好きな値を設定することができます。
どの動物もメンバ関数を使えるようにしなければなりません。
`makeSound()`
適切な音が印刷されます（猫は吠えません）。

このコードを実行すると、Animalの音ではなく、DogとCatのクラスの固有の音が出力されます。
```c
    int main()
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        ...
        return 0;
    }
```
この仕組みを理解するために、WrongAnimalクラスを継承したWrongCatクラスを実装してみましょう。上のコードでAnimalとCatを入れ替えると、WrongCatはWrongAnimalの音を出力するはずです。
上記以外のテストも実装して提出しなさい。

## Chapter IV Exercise 01: I don’t want to set the world on fire
- Turn-in directory : ex01/
- Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
- Forbidden functions : None
各クラスのコンストラクタとデストラクタは、特定のメッセージを表示する必要があります。
Brainクラスを実装します。このクラスにはideaと呼ばれる100個のstd::stringの配列が含まれています。
こうすることで、DogとCatはプライベートBrain*属性を持つことになります。
構築時に、DogとCatはnew Brain()を使ってBrainを作成します。
破壊されると、DogとCatはBrainを削除します。
メイン関数では、Animalオブジェクトの配列を作成し、それを埋めてください。半分がDog、もう半分がCatのオブジェクトになります。プログラム終了時に、この配列をループして、すべてのAnimalを削除してください。このとき、Animalとして、DogとCatを直接削除してください。適切なデストラクタを適切な順序で呼び出す必要があります。
メモリリークのチェックも忘れずに。
犬や猫のコピーは浅くてはいけません。したがって、コピーがディープコピーであることをテストしなければなりません。

```cpp
    int main()
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
        ...
        return 0;
    }
```
Implement and turn in more tests than the ones given above.

## Chapter V Exercise 02: Abstract class
- Turn-in directory : ex02/
- Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
- Forbidden functions : None
アニマルオブジェクトを作っても、やっぱり意味がない。そうなんです、音を出さないんです。
間違いが起きないように、デフォルトのAnimalクラスはインスタンス化できないようにします。
Animalクラスをインスタンス化できないように修正します。これで、以前と同じように動作するはずです。
必要であれば、Animalの前にAを付けて、クラス名を更新することができます。

## Chapter VI Exercise 03: Interface & recap
- Turn-in directory : ex03/
- Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
- Forbidden functions : None
C++98にはインターフェイスは存在しません（C++20にも存在しません）。しかし、純粋な抽象クラスは一般にインターフェースと呼ばれます。したがって、この最後の演習では、このモジュールを手に入れたことを確認するために、 インターフェイスを実装してみましょう。
以下のAMateriaクラスの定義を完成させ、必要なメンバ関数を実装してください。
```cpp
    class AMateria
    {
    protected:
    [...]
    public:
    AMateria(std::string const & type);
    [...]
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    };
```

Materias の具象クラス Ice と Cure を実装します。それぞれの名前を小文字にして（Iceなら "ice"、Cureなら "cure"）、型を設定する。もちろん、メンバ関数clone()は同じ型の新しいインスタンスを返します（つまり、Ice Materiaをcloneすると、新しいIce Materiaが得られます）。
use(ICharacter&)メンバ関数は、表示されます。
- Ice: "* shoots an ice bolt at <name> *"
- Cure: "* heals <name>’s wounds *"
<name>はパラメータとして渡されるキャラクタの名前です。山括弧(<と>)は表示しないようにします。
マテリアを別のものに代入するとき、型をコピーしても意味がない。
以下のインターフェイスを実装した具象クラス Character を作成しなさい。

```cpp
    class ICharacter
    {
        public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
    };
```

このキャラクターは4つのインベントリを所持しており、最大で4つのマテリアを所持していることになります。
建設時、インベントリは空です。最初に見つけた空のスロットにマテリアを装備します。つまり、スロット0からスロット3までの順番で装備することになります。万が一、満杯のインベントリにマテリアを追加しようとしたり、既存のマテリアを使用・装備解除しようとしても、何もしないこと（ただし、バグは禁止されている）。unequip()関数は、マテリアを削除してはいけません!
キャラクターが床に置いたままのマテリアは、好きなように処理してください。
unequip()を呼ぶ前にアドレスを保存しておくなどして、メモリリークを回避することを忘れないでください。
use(int, ICharacter&) メンバ関数はスロット[idx]にあるマテリアを使用し、AMateria::use関数にターゲットパラメータを渡す必要があります。

キャラクターのインベントリは、あらゆる種類のAMateriaをサポートできるようになります。
キャラクターには、その名前をパラメータとして受け取るコンストラクタが必要です。キャラクターのコピー（コピーコンストラクタまたはコピー代入演算子を使用）は、深いものでなければなりません。
コピー中は、新しいマテリアがインベントリに追加される前に、キャラクターのマテリアを削除する必要があります。もちろん、キャラクターが破壊されたときにも、マテリアは削除されなければなりません。
以下のインターフェイスを実装した具象クラスMateriaSourceを作成します。

```cpp
    class IMateriaSource
    {
        public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
    };
```
- learnMateria(AMateria*)
パラメータとして渡されたマテリアをコピーしてメモリに保存し、後でクローンできるようにします。キャラクターと同様、MateriaSourceは最大で4つのマテリアを知ることができます。それらは必ずしもユニークなものではありません。
- createMateria(std::string const &)
新しいMateriaを返します。後者はMateriaSourceが以前に学習したMateriaのコピーで、その型はパラメータとして渡されたものと同じである。型が不明な場合は0を返します。
簡単に言うと、MateriaSourceはMateriaの "テンプレート "を学習して、必要なときにMateriaを生成できるようにする必要があります。そうすれば、型を特定する文字列だけで、新しいマテリアを生成することができるようになる。

Running this code:
```cpp
    int main()
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
        return 0;
    }
```
Should output:
```output
    $> clang++ -W -Wall -Werror *.cpp
    $> ./a.out | cat -e
    * shoots an ice bolt at bob *$
    * heals bob's wounds *$
    As usual, implement and turn in more tests than the ones given above.
```