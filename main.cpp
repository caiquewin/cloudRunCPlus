#include <iostream>
#include "httplib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace httplib;

int main() {
    Server svr;


    svr.Post("/", [](const Request& req, Response& res) {
        try {
            std::string name;
            std::int idade;
            auto body_json = json::parse(req.body);
            name = body_json.value("name", "mundo");
            idade = body_json.value("old", "mundo");
            
            json response = {
                {"message", "Olá, " + name}
                {"idade", idade}
            };

            res.set_content(response.dump(), "application/json");
        } catch (const std::exception& e) {
            json error = {{"error", e.what()}};
            res.status = 400;
            res.set_content(error.dump(), "application/json");
        }
    });

    std::cout << "Servidor rodando na porta 8080..." << std::endl;
    svr.listen("0.0.0.0", 8080);
}