openMSX 21.0-390 for MAmidiMEmo

- openmsx.exe ... ver 21.0-386
  MAMI非対応
  私的な日本向け修正のみ

- openmsx_for_mami.exe ... ver 21.0-390
  MAMI対応版（MAmidiMEmoに演奏情報を送信できます）
  私的な日本向け修正

  - 使い方は 
    https://github.com/uniskie/MSX_DOCUMENTS/blob/main/MAmidiMEmoNEMO/readMe.md
    参照

- 私的パッチ:  
  - テンキーのカンマ入力不能問題の修正
  - IME自動抑制
  - 左右SHIFT同時押し対策 → 潜在的な問題があるので修正予定
  - 起動時とメニュー操作後に起きる入力フォーカス喪失の修正

## リベース元：公式版

リビジョン: 5dd287317985929fe630aa4973f44455917385bc
作者: f-fix <bsittler@iname.com>
日時: 2026/07/09 木曜日 12:51:54

## 日本語キーボード問題について

公式版OpenMSXでもキー配列（POSITION限定）とUIの日本語化けは対策済みです。
漢字モード自動無効化は入っていませんが、対策(後述)がありますので、
基本的には公式版OpenMSXをお勧めします。

### 公式OpenMSXを使用する際の漢字モード対策

Windowsの言語設定にUSを追加、USのキーボード配列を日本語キーボードに変更。
OpenMSX使用時にWIN+SPACEでUS/日本を切り替えで対応
というのを推奨しています。
（公式OS依存かつ日本語限定の機能を入れるにはテスター不足なので）

### CAPSキー問題

WindowsではCAPS LOCKキーが押しっぱなしになる問題があります。
対策としては
1. 別のキーにbindする
2. 秀CAPS等で英数とCAPS LOCKを入れ替える  
   （CAPS単体では反応しなくなり、SHIFT+CAPSで切り替えになる）
などがあります。

## 更新

- openMSX 21.0-386 and "for MAmidiMEmo" ver

  - テンキーのカンマが入力できない問題の修正
  - 公式最新リポジトリ取り込み

- openMSX 21.0-272 and "for MAmidiMEmo" ver

  - 起動時とメニュー操作後に起きる入力フォーカス喪失の修正
  - 公式最新リポジトリ取り込み

- openMSX 21.0-267 and "for MAmidiMEmo" ver

	- 公式リポジトリ取り込み

- openMSX 20.0-98 and "for MAmidiMEmo" ver

  - 公式最新リポジトリに反映されたGUIフォントのマルチバイト文字修正取り込み

- openMSX 20.0-545b and "for MAmidiMEmo" ver

  - 公式最新リポジトリに反映されたGUIフォントの修正取り込み
  - それに伴い、暫定的な日本語フォント対応を取り消し

- openMSX 20.0-521b and "for MAmidiMEmo" ver

  - 公式最新リポジトリの取り込み
  - バージョン表記をmasterリポジトリから自動生成された物に変更
  - GUIで日本語漢字が表示できるように変更（thanks for @pman4416）

- openMSX 20.0-9b and "for MAmidiMEmo" ver

  公式最新リポジトリの取り込み


- openMSX 20.0-8b and "for MAmidiMEmo" ver

  公式最新リポジトリの取り込み

- openMSX 20.0-8b and "for MAmidiMEmo" ver
  
  - メインウィンドウでIMEを無効化するように変更。
    サブウインドウや他のウィンドウでは戻し、メインウィンドウに戻ったら再び無効化する形です。
  
    また setting に kbd_disable_IME を追加しています。
    デフォルト値はtrueで、メインウィドウでIMEを無効化します。
    F10で表示できるコンソールから
    ```set kbd_disable_IME false⏎```
    と入力すれば、IMEを有効化できます。（他のウィンドウに移動してから戻ってみてください）
  
    > 現状、メニューでもサブウィンドウでもMSX側でも日本語を正常処理できない実装なので、意味はないのですが
    > 将来日本語入力表示に対応したいとか、IMEを使いたい場合に有効化できるようにしておきました。

  - （前回の更新補足）
    MAMIへの通信時に接続チェックを挟むようにしたところ、
    リバースバー/ステートロード/マシン一覧/デバイス一覧の速度低下が少し緩和した様子。
  

- openMSX 20.0-7b and "for MAmidiMEmo" ver

  - SHIFTなどの複数存在するキーの同時押しで、どれかを先に離すとMSX側では全部離したことになってしまう問題の対処を追加。
    （秀CAPSなどで「SHIFTを押さずに"_"」機能を使用している場合でも_や♦が入力できます）
    ホストキーボードイベントのみを対象にした管理をしているので副作用は無いと思いますが、暫く検証は必要かと思います。
  
  - MAMIへのrpc送信時に接続状態をチェックして、余計な例外を出さないように修正

- openMSX 20.0-5b and "for MAmidiMEmo" ver

  - キーボード入力できないキーがある問題の修正
    解決できたのはPOSITIONALモードだけです。
  
    > Settings → Input → Keyboard mapping mode: POSITIONAL に設定してください。
  
    **KEYモードやCHARACTERモードは仕様的に問題があるので、私は修正対応するつもりはありません。（出来ません）**
  
    - キースキャンコードがマップされていないUS圏以外のキーを追加
      （"￥"がINTERNATIONAL3、"＼_ろ"がNONUSBACKSLASH）
  
    - 日本語キーボードの"］"が"￥"扱いになってしまう問題の修正
      日本語キーボードの様に、USのバックスラッシュの位置に"]"がある配列の時に位置を補正します。
      （そういう配列の物はNONUSBACKSLASHやINTERNATIONAL3が＼や通貨文字の様子）
  
    ちなみにSHIFT+CAPSでないとCAPSロックが正常動作しない問題は解決が難しいので、SHIFT+CAPSでの入力を徹底するか、別のキーにCAPSをバインドしてみてください。

## 用途や使い方

MAmidiMEmoとの連携方法などは
こちらを参照ください。

https://github.com/uniskie/MSX_DOCUMENTS/blob/main/MAmidiMEmoNEMO/readMe.md

