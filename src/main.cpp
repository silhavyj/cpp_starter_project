#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <cxxopts.hpp>
#include <magic_enum/magic_enum.hpp>
#include <nlohmann/json.hpp>

int main() {
    fmt::print("{1} {0}\n", "World!", "Hello");

    cxxopts::Options options("MyProgram", "One line description of MyProgram");

    options.add_options()
        ("d,debug", "Enable debugging") // a bool parameter
        ("i,integer", "Int param", cxxopts::value<int>())
        ("f,file", "File name", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
    ;

    fmt::print("{}", options.help());

    enum Color { RED, BLUE, WHITE, GREEN };
    constexpr auto color_count = magic_enum::enum_count<Color>();
    fmt::print("count = {}\n", color_count);

    nlohmann::json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
            {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
            {"currency", "USD"},
            {"value", 42.99}
        }}
    };

    fmt::print("{}", j2.dump());

    return 0;
}