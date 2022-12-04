# Subject
## Chapter 2
Introduction

This project aims to introduce you to the wonderful world of virtualization.
You will create your first machine in VirtualBox (or UTM if you can’t use VirtualBox)
under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.

このプロジェクトは、仮想化という素晴らしい世界を紹介することを目的としています。
VirtualBox（VirtualBoxを使用できない場合はUTM）で最初のマシンを作成します。
特定の指示の下で。そして、このプロジェクトの最後には、厳密なルールを実行しながら、独自のOSをセットアップすることができるようになります。

---

## Chapter 3

General guidelines
- The use of VirtualBox (or UTM if you can’t use VirtualBox) is mandatory.
- You only have to turn in a signature.txt file at the root of your repository. You
must paste in it the signature of your machine’s virtual disk. Go to Submission and
peer-evaluation for more information.

一般的なガイドライン
- VirtualBoxの使用（VirtualBoxが使用できない場合はUTMの使用）を必須とします。
- リポジトリのルートに signature.txt ファイルを提出するだけです。その中に自分のマシンの仮想ディスクの署名を貼り付ける必要があります。詳しくは提出と相互評価へ。

---

## Chapter 4

Mandatory part
This project consists of having you set up your first server by following specific rules.

Since it is a matter of setting up a server, you will install the minimum of services. For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other equivalent graphics server. Otherwise, your grade will be 0.

You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of CentOS. Debian is highly recommended if you are new to system administration.

Setting up CentOS is quite complex. Therefore, you don’t have to set up KDump. However, SELinux must be running at startup and its configuration has to be adapted for the project’s needs. AppArmor for Debian must be running at startup too.

You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning:

必須項目
このプロジェクトは、特定のルールに従って最初のサーバを立ち上げてもらうことで構成されています。

サーバーを立ち上げるということなので、最低限のサービスをインストールすることになります。そのため、グラフィカルインターフェースはここでは役に立ちません。したがって、X.orgやその他の同等のグラフィックサーバーをインストールすることは禁じられています。さもなければ、あなたの成績は0点となります。

オペレーティングシステムは、Debian の最新安定版 (testing/unstable なし) か、CentOS の最新安定版のどちらかを選択する必要があります。システム管理の経験が浅い場合は Debian を強くお勧めします。

CentOSのセットアップはかなり複雑です。そのため、KDumpを設定する必要はありません。ただし、SELinuxはスタートアップ時に起動している必要があり、その設定はプロジェクトのニーズに合わせて変更する必要があります。AppArmor for Debianも起動時に起動しておく必要があります。

LVMを使用して、少なくとも2つの暗号化パーティションを作成する必要があります。以下は、予想されるパーティション分割の例です。

---

During the defense, you will be asked a few questions about the operating system you chose. For instance, you should know the differences between aptitude and apt, or what SELinux or AppArmor is. In short, understand what you use!

A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.

The use of SSH will be tested during the defense by setting up a new account. You must therefore understand how it works.

You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.

Your firewall must be active when you launch your virtual machine. For CentOS, you have to use UFW instead of the default firewall. To install it, you will probably need DNF.

- The hostname of your virtual machine must be your login ending with 42 (e.g., wil42). You will have to modify this hostname during your evaluation.
- You have to implement a strong password policy.
- You have to install and configure sudo following strict rules.
- In addition to the root user, a user with your login as username has to be present.
- This user has to belong to the user42 and sudo groups.

During the defense, you will have to create a new user and assign it to a group.

To set up a strong password policy, you have to comply with the following requirements:
- Your password has to expire every 30 days.
- The minimum number of days allowed before the modification of a password will
 be set to 2.
- The user has to receive a warning message 7 days before their password expires.
- Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
- The password must not include the name of the user.
- The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
- Of course, your root password has to comply with this policy.

ディフェンスでは、選んだOSについていくつか質問されます。例えば、aptitudeとaptの違いや、SELinuxやAppArmorが何なのかを知っておくとよいでしょう。要するに、自分が使っているものを理解することです!

SSH サービスはポート 4242 のみで実行されます。セキュリティ上の理由から、root で SSH を使って接続することはできないようにしなければなりません。

SSHの使用は、新しいアカウントを設定することによって、防衛中にテストされます。そのため、どのように動作するかを理解しておく必要があります。

オペレーティングシステムにUFWファイアウォールを設定し、ポート4242のみを開放しておく必要があります。

仮想マシンを起動する際には、ファイアウォールが有効である必要があります。CentOSの場合、デフォルトのファイアウォールの代わりに、UFWを使用する必要があります。これをインストールするには、DNFが必要でしょう。

- 仮想マシンのホスト名は、42で終わるログイン名である必要があります（例：wil42）。評価中にこのホスト名を変更する必要があります。
- 強力なパスワードポリシーを実装する必要があります。
- 厳密なルールに従ってsudoをインストールし、設定しなければなりません。
- root ユーザに加えて、ユーザ名としてあなたのログインを持つユーザが存在しなければなりません。
- このユーザーは user42 と sudo グループに属していなければなりません。

防御の間、あなたは新しいユーザーを作成し、それをグループに割り当てる必要があります。

強力なパスワードポリシーを設定するには、次の要件に準拠する必要があります。
- パスワードは30日ごとに失効しなければならない。
- パスワードが変更されるまでに許容される最小日数は2に設定される。
- パスワードの有効期限が切れる7日前に、ユーザーに警告メッセージを表示する必要があります。
- パスワードは10文字以上でなければなりません。大文字と数字が含まれていなければなりません。また、同じ文字が3つ以上連続して含まれていてはいけません。
- パスワードにユーザー名を含んではならない。
- ルートパスワードには、次のルールは適用されません：パスワードには、以前のパスワードに含まれていない文字が少なくとも7文字含まれていなければなりません。
- もちろん、rootパスワードは、このポリシーに従わなければなりません。

After setting up your configuration files, you will have to change all the passwords of the accounts present on the virtual machine, including the root account.

To set up a strong configuration for your sudo group, you have to comply with the following requirements:
- Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
- A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
- Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
- The TTY mode has to be enabled for security reasons.
- For security reasons too, the paths that can be used by sudo must be restricted.
Example:
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

設定ファイルの作成後、rootアカウントを含む、仮想マシン上に存在するすべてのアカウントのパスワードを変更する必要があります。

sudoグループに強力な設定を行うには、以下の要件に準拠する必要があります。
- sudo を使用した認証は、パスワードが間違っている場合の試行回数を 3 回に制限する必要があります。
- sudoを使用する際、パスワードの間違いによるエラーが発生した場合、選択したカスタムメッセージを表示する必要があります。
- sudoを使用する各アクションは、入力と出力の両方がアーカイブされなければならない。ログファイルは、/var/log/sudo/ フォルダーに保存されなければなりません。
- セキュリティ上の理由から、TTYモードを有効にする必要があります。
- セキュリティ上の理由から、sudo が使用できるパスを制限する必要があります。
例
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

---

Finally, you have to create a simple script called monitoring.sh. It must be devel- oped in bash.
At server startup, the script will display some information (listed below) on all terminals every 10 minutes (take a look at wall). The banner is optional. No error must be visible.
Your script must always be able to display the following information:
- The architecture of your operating system and its kernel version.
- The number of physical processors.
- The number of virtual processors.
- The current available RAM on your server and its utilization rate as a percentage.
- The current available memory on your server and its utilization rate as a percentage.
- The current utilization rate of your processors as a percentage.
- The date and time of the last reboot.
- Whether LVM is active or not.
- The number of active connections.
- The number of users using the server.
- The IPv4 address of your server and its MAC (Media Access Control) address.
- The number of commands executed with the sudo program.
During the defense, you will be asked to explain how this script works. You will also have to interrupt it without modifying it. Take a look at cron.

This is an example of how the script is expected to work:

最後に、monitoring.shという簡単なスクリプトを作成する必要があります。これはbashで開発されなければなりません。
サーバ起動時に、このスクリプトは10分ごとにいくつかの情報(以下のリスト)をすべての端末に表示します(wallを見てみてください)。バナーは任意です。エラーは表示されてはならない。
スクリプトは常に以下の情報を表示できるようにしなければならない。
- オペレーティングシステムのアーキテクチャとそのカーネルバージョン。
- 物理プロセッサの数
- 仮想プロセッサの数
- サーバー上で現在使用可能なRAMとその使用率（パーセンテージ）。
- サーバー上で現在利用可能なメモリとその使用率（パーセンテージ）。
- プロセッサの現在の使用率（%）。
- 最後に再起動した日付と時刻。
- LVMがアクティブかどうか。
- アクティブな接続数。
- サーバーを使用しているユーザー数。
- サーバーのIPv4アドレスとそのMAC（Media Access Control）アドレス。
- sudo プログラムで実行されたコマンドの数。
防御の間、あなたはこのスクリプトがどのように動作するかを説明するよう求められます。また、それを修正せずに中断する必要があります。cronを覗いてみてください。

これは、このスクリプトがどのように動作することが期待されるかの例です。

Broadcast message from root@wil (tty1) (Sun Apr 25 15:45:00 2021):
#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%)
#Disk Usage: 1009/2Gb (39%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connections TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd

---

Below are two commands you can use to check some of the subject’s requirements:
以下は、被写体の条件の一部を確認するために使用できる2つのコマンドです。

---

## Chapter 5

Bonus list:
- Set up partitions correctly so you get a structure similar to the one below:
- Set up a functional WordPress website with the following services: lighttpd, MariaDB, and PHP.
- Set up a service of your choice that you think is useful (NGINX / Apache2 excluded!). During the defense, you will have to justify your choice.

To complete the bonus part, you have the possibility to set up extra services. In this case, you may open more ports to suit your needs. Of course, the UFW rules has to be adapted accordingly.

ボーナスリスト
- パーティションを正しく設定し、以下のような構造になるようにします。
- 機能的なWordPressウェブサイトを、次のサービスとともにセットアップする：lighttpd、MariaDB、PHP。
- あなたが便利だと思う好きなサービスをセットアップする（NGINX / Apache2は除く！）。NGINX / Apache2は除く！）防衛の間、あなたはあなたの選択を正当化する必要があります。

ボーナス・パートを完了するために、あなたは追加のサービスをセットアップする可能性があります。この場合、あなたのニーズに合わせて、より多くのポートを開くことができます。もちろん、UFWのルールは、それに応じて適応されなければならない。

---

The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

ボーナスパーツは、必須パーツがPERFECTである場合にのみ査定されます。パーフェクトとは、必須パートが統合的に行われ、誤動作することなく動作することを意味します。必須条件をすべてクリアしていない場合、ボーナスパーツの評価は一切行われません。

---

## Chapter VI
Submission and peer-evaluation
You only have to turn in a signature.txt file at the root of your Git repository. You must paste in it the signature of your machine’s virtual disk. To get this signature, you first have to open the default installation folder (it is the folder where your VMs are saved):

- Windows: %HOMEDRIVE%%HOMEPATH%\VirtualBox VMs\
- Linux: ~/VirtualBox VMs/
- MacM1: ~/Library/Containers/com.utmapp.UTM/Data/Documents/
- MacOS: ~/VirtualBox VMs/

Then, retrieve the signature from the ".vdi" file (or ".qcow2 for UTM’users) of your virtual machine in sha1 format. Below are 4 command examples for a centos_serv.vdi

file:
- Windows: certUtil -hashfile centos_serv.vdi sha1
- Linux: sha1sum centos_serv.vdi
- For Mac M1: shasum Centos.utm/Images/disk-0.qcow2
- MacOS: shasum centos_serv.vdi

This is an example of what kind of output you will get:

- 6e657c4619944be17df3c31faa030c25e43e40af

Please note that your virtual machine’s signature may be altered after your first evaluation. To solve this problem, you can duplicate your virtual machine or use save state.

It is of course FORBIDDEN to turn in your virtual machine in your Git repository. During the defense, the signature of the signature.txt file will be compared with the one of your virtual machine. If the two of them are not identical, your grade will be 0. 

## 第六章
提出と相互評価
Git リポジトリのルートに signature.txt ファイルを提出するだけです。その中に、あなたのマシンの仮想ディスクの署名を貼り付けなければなりません。この署名を得るには、まずデフォルトのインストールフォルダを開く必要があります（あなたのVMが保存されているフォルダです）。

- Windows: %HOMEDRIVE%%HOMEPATH%ThreeVirtualBox VMs
- Linux: ~/VirtualBox VMs/ (英語)
- MacM1: ~/Library/Containers/com.utmapp.UTM/Data/Documents/。
- MacOS: ~/VirtualBox VMs/ です。

次に、仮想マシンの「.vdi」ファイル（UTM'ユーザは「.qcow2」）から署名をsha1形式で取り込みます。以下は、centos_serv.vdiに対する4つのコマンド例です。

ファイルを作成します。
- Windows: certUtil -hashfile centos_serv.vdi sha1
- Linux: sha1sum centos_serv.vdi
- Mac M1の場合：shasum Centos.utm/Images/disk-0.qcow2
- MacOS: shasum centos_serv.vdi

どのような出力が得られるかの一例です。

- 6e657c4619944be17df3c31faa030c25e43e40af

最初の評価後、仮想マシンの署名が変更される可能性があることにご注意ください。この問題を解決するには、仮想マシンを複製するか、セーブステートを使用します。

もちろん、仮想マシンをGitリポジトリに提出することはFORBIDDENです。防御の間、signature.txtファイルの署名は、あなたの仮想マシンの署名と比較されます。もし両者が同一でない場合、あなたの成績は0点となります。