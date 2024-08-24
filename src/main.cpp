#include <nlohmann/json.hpp>

#include <iostream>
#include <vector>

int main()
{
    using json = nlohmann::json;

    const json ex1 = json::parse(R"(
    {
        "happy": true,
        "pi": 3.141,
        "日本語": {
            "漢字": "世界",
            "かな": "こんにちは"
        }
    }
    )");

    const auto kana = ex1["日本語"]["かな"]; // これはstringではない
    std::cout << kana << std::endl;

    const auto kanji = ex1["日本語"]["漢字"].get<std::string>(); // これはstring
    std::cout << kanji << std::endl;

    const auto dumped = ex1.dump();
    std::cout << dumped << std::endl;

    std::vector<char> bytes(dumped.size());
    std::copy(dumped.begin(), dumped.end(), bytes.begin());
    for (const auto &byte : bytes)
    {
        std::cout << int(byte) << " ";
    }
    std::cout << std::endl;
}
