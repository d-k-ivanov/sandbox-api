/*
 * =====================================================================
 *      Project :  cpp-rest-api-svs
 *      File    :  main.cpp
 *      Created :  21/09/2020 03:30:00 +0300
 *      Author  :  Dmitriy Ivanov
 * =====================================================================
 */

#include "main.h"

#include <cxxopts.hpp>

#include <functional>
#include <filesystem>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace fs = std::filesystem;

int main(int argc, char* argv[], char* env[])
 {
    // To turn off messages about unused variables.
    // ((void)argc );
    // ((void)argv );
    ((void)env );

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    const fs::path applicationFullPath = argv[0];
    auto applicationPath = applicationFullPath.parent_path();
    const auto applicationName = applicationFullPath.filename().replace_extension("");


    cxxopts::Options options(applicationName.string(), "Description");
    options
        .positional_help("[optional args]")
        .show_positional_help();

    options.add_options()
        ("h,help",      "Show help")
        ("a,action",    "Action",       cxxopts::value<std::string>())
        ("p,path",      "Path to file", cxxopts::value<std::string>());

    options.custom_help("[-h] [-a] [-p]");

    try {
        options.parse_positional({ "action", "path" });
        const auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << '\n';
            exit(1);
        }

        if (result.count("action")) {
            std::cout << "action: " << result["action"].as<std::string>() << std::endl;
        }

        if (result.count("path")) {
            std::cout << "path: "  << result["path"].as<std::string>() << std::endl;
        }

    }
    catch (const cxxopts::OptionException & e) {
        std::cout << "Error: " << e.what() << " Showing help message...\n";
        std::cout << options.help() << '\n';
        exit(99);
    }

    std::system("pause");

    return 0;
 }
