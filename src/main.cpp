#include <iostream>
#include <vector>
#include <memory>
#include <filesystem>

template <typename T>
void printVector(const std::vector<T> &vector)
{
    for (const auto &i : vector)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main()
{
     std::cout << "+- -- -- -- -- -- -- -- -- +\n"
              << "| 35.6 Task 3 (to lesson 4)|\n"
              << "+- -- -- -- -- -- -- -- -- +\n\n";

     auto getFilesWithExtension = [](const std::filesystem::path &path, const std::string &extension) -> std::unique_ptr<std::vector<std::filesystem::path>>
     {
         std::cout << "Getting filenames with extension " << extension << " in path " << path << "...\n";
         auto result = std::make_unique<std::vector<std::filesystem::path>>();
         auto *paths = new std::filesystem::recursive_directory_iterator(path);
         for (const auto &p : *paths)
         {
             if (p.is_regular_file())
             {
                 if (p.path().extension().compare(extension) == 0)
                 {
                     result->push_back(p.path().filename());
                 }
             }
         }
         return result;
     };
     std::filesystem::path path = "..//TestDir";
     std::string extension = ".jpg";
     try
     {
         auto fileNames = getFilesWithExtension(path, extension);
         std::cout << "File names in " << path << " with extension " << extension << ":\n";
         printVector(*fileNames);
     }
     catch (const std::exception &e)
     {
         std::cerr << e.what();
     }
     std::cout <<"\n\n";
}