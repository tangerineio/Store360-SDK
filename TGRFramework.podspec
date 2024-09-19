Pod::Spec.new do |s|
  s.name         = 'TGRFramework'  # ライブラリの名前
  s.version      = '2.4.4'         # バージョン番号
  s.summary      = 'A short description of TGRFramework'  # 短い説明
  s.description  = 'A longer description of what TGRFramework does'  # 詳細な説明
  s.homepage     = 'https://github.com/tangerineio/Store360-SDK'  # ライブラリのホームページ
  s.license      = { :type => 'MIT', :file => 'LICENSE' }  # ライセンス情報
  s.author       = { 'YourName' => 'your.email@example.com' }  # 作者の名前とメールアドレス
  s.source       = { :git => 'https://github.com/tangerineio/Store360-SDK.git', :tag => s.version.to_s }  # ソースコードのURLとタグ

  s.platform     = :ios, '13.0'  # 対応するプラットフォームとバージョン
  s.vendored_frameworks = 'Frameworks/TGRFramework.xcframework'  # バイナリフレームワークのパス
end
