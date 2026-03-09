#include "Serializer.hpp"
#include <iostream>

int main()
{
  Data data;
  data.id = 42;
  data.name = "hello";

  std::cout << "Original pointer: " << &data << std::endl;
  std::cout << "Data id: " << data.id << ", name: " << data.name << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized: " << raw << std::endl;

  Data *ptr = Serializer::deserialize(raw);
  std::cout << "Deserialized pointer: " << ptr << std::endl;
  std::cout << "Data id: " << ptr->id << ", name: " << ptr->name << std::endl;

  if (ptr == &data)
    std::cout << "Success: pointers are equal!" << std::endl;
  else
    std::cout << "Failure: pointers differ!" << std::endl;

  return 0;
}
