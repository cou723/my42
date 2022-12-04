## 細かな仕様
- is何たら系はcharになおせない値の場合は未定義(ISO C90)
- callocは0が渡された場合NULLかユニークポインタである必要がある（ISO C90）
- atoiで数字が変換できない時返り値は未定義（ISO C90）

## ft_memcmpの文字数が多すぎてオーバーフローする問題
totalの内容がintを超える場合があるので直接リターンはしない
```c
if(s1_total == s2_total)
		return (0);
	else if(s1_total > s2_total)
		return (1);
	else
		return (-1);
		
```

## ft_split

### やり方

1. strをトリムする
2. 一文字ずつみていく
while 3. cまでのメモリを確保する
while 4. もし、cが見つかった場合i_strを進め
while 5. cが見つからない位置までポインタをすすめる
while 終了条件:strがnullを取得した場合

### エッジケース一覧
- strが`\0`
- cが`\0`
- strが極端に長い

## 気を付けるべき点
- 文字列が渡される場合はnull文字終端が保障されている前提で実装をしていいが、それ以外のポインタの場合はNULL参照を気を付けたほうがよさそう
- 渡される文字列の長さが0の時に意識してるか？
- オーバーフローを意識してるか？

## ft_substr
strのヌルチェックをしていない理由はNULLが変えるのはallocation failsの時のみにしたいから
strがNULLだとセグフォ
strdup("")を返すのはstartがおかしかった時のみだから返せない

## ft_strjoin
strdup("")は返せない
NULLもallocation failsと混同するから返せない

## 

## 

## libft unit testおかしいやつ
isalnum
toupper
tolower
strdup
substr(3)
strjoin
strmapi(1)(3)
