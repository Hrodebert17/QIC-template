#include "qic.h"
#include <any>
#include <iostream>
#include <unordered_map>

int main() {
  data_base db;

  // Open the database
  db.open_database("mydatabase.db");

  // Create a table
  auto op = db.add_table("COMPANY", std::unordered_map<std::string, data_type>{
                                        {"ID", INT},
                                        {"NAME", STRING},
                                        {"AGE", INT},
                                        {"ADDRESS", STRING},
                                        {"SALARY", DOUBLE}});
  if (op.stat == FAILED) {
    std::cout << "Error: " << op.error << std::endl;
  } else {
    std::cout << "Table created successfully!" << std::endl;
  }

  // Add a record to the table
  op = db.add_value("COMPANY",
                    std::unordered_map<std::string, std::any>{
                        {"ID", std::any(0)},
                        {"NAME", std::any(std::string("Hrodebert"))},
                        {"AGE", std::any(120)},
                        {"ADDRESS", std::any(std::string("not known"))},
                        {"SALARY", std::any((double)0)}});
  if (op.stat == FAILED) {
    std::cout << "Error: " << op.error << std::endl;
  } else {
    std::cout << "Record added successfully!" << std::endl;
  }

  // Save the changes
  db.save();
  std::cout << "Changes saved successfully!" << std::endl;

  // Close the database
  db.close();
  std::cout << "Database closed successfully!" << std::endl;

  return 0;
}

