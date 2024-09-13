// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription
let package = Package(
    name: "TGRFramework",
    platforms: [
        .iOS(.v13), // 対応するプラットフォームとバージョンを指定します
    ],
    products: [
        .library(
            name: "TGRFramework",
            targets: ["TGRFramework"]), // 2つのターゲットを指定]), // 2つのターゲットを指定]),
    ],
    targets: [
        .binaryTarget(
            name: "TGRFramework",
            path: "./Frameworks/TGRFramework.xcframework")
    ]
)
