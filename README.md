# 環境構築
* platformioのインストール(Arduino IDEを使っても良いが少し手順が変わる)
```bash
$ python -m pip install -U platformio
```

* リポジトリをclone
```bash
$ git clone git@github.com:bee-tk/co2_sensor.git
```

# 使い方
* firmwareの書き換え

co2_sensor/src/main.cppを編集する。setup()は一度のみ実行され、loop()は無限ループされる関数

* M5StickC PlusをPCと接続して、以下のコマンドでビルド、実機へのインストールが出来る
```bash
$ cd co2_sensor
$ pio run -t upload
```

* debug方法（シリアルモニター機能を使うことでログ出力できる）
```bash
$ pio device monitor
```
