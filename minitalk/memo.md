sigactionとsignal,signalのほうがLinuxのバージョンによって挙動が違い移植性が低いためsigactionの仕様が推奨される。

## sigaction
sigaction構造体
```c
struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void); 
};
```
- sa_handler
- sa_sigaction
  - sa_handlerかsa_sigactionを設定する必要がある。sa_flagsでSA_SAGINFOを指定するとsa_sigactionを、指定しないとsa_handlerが使用される。
- sa_mask
  - opt
- sa_flags
  - 必須
  - シグナルハンドラーの動作を変更するためのフラグの集合(論理和)を指定する
- sa_restorer
  - アプリケーション側での使用は想定されていない

## なんだこれ？
```c
void    send_char(pid_t pid, char c)
{
    int             bit;
    int             i;
    unsigned char   uc;

    uc = (unsigned char)c;
    i = 0;
    while (i < 8)
    {
        usleep(50);
        bit = (uc >> i) & 0x01;
        if (kill(pid, SIGUSR1 + bit) == -1)
            fatal("kill error");
        i++;
    }
}
```
```
10101010
00000001
00000001
1

00000010
00000001
0

00000101
00000001
1

10101010
00001010
00000001
0
```

&演算子は>>で求めたい桁数分シフトするとその桁のビットを取得する際に使える

## signalの内容はどこで送れば？
要するにだれ(pid)にどこ(signal)で何(??)を渡すかを定義したい
何(??)を定義する方法がわからなかったが、要するにSIGUSR1で送ったら1を送る。SIGUSR2で送ったら0を送る。みたいに決めて送る必要があるみたい。

## 反省点
oファイルがないってことは再コンパイルしない、client
argsなしで実行すると死ぬ