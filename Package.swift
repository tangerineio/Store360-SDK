// swift-tools-version: 5.10
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
            targets: ["TGRFramework"]),
    ],
    targets: [
        .binaryTarget(
            name: "TGRFramework",
            path: "./Frameworks/TGRFramework.xcframework")
    ]
)
