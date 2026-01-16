#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::cout << "TEST" << std:endl;

    std::cout << "==================================" << std::endl;
    std::cout << "  Sample C++ Application" << std::endl;
    std::cout << "==================================" << std::endl;
    
    std::cout << "\nBuild Information:" << std::endl;
    std::cout << "  Compiler: " << 
#ifdef __GNUC__
        "GCC " << __GNUC__ << "." << __GNUC_MINOR__
#elif defined(__clang__)
        "Clang " << __clang_major__ << "." << __clang_minor__
#else
        "Unknown"
#endif
        << std::endl;
    
    std::cout << "  Build Type: "
#ifdef NDEBUG
        << "Release"
#else
        << "Debug"
#endif
        << std::endl;
    
    if (argc > 1) {
        std::cout << "\nArguments:" << std::endl;
        for (int i = 1; i < argc; ++i) {
            std::cout << "  [" << i << "] " << argv[i] << std::endl;
        }
    }
    
    std::cout << "\n✅ Application executed successfully!" << std::endl;
    return 0;
}
