# readcsv
CSVデータを読み取る。

## 仕様
元の三重ポインタから仕様を変更し、データ型を識別して構造体に格納する方式に変更	

# 使える関数
- readcsv(char * filename);
	csvをファイル名から読み取ります

- print_table(char ***table);
	テーブルを表示します

- freetable(char ***table);
	テーブルを開放します。
