// File: src/server.cpp
#include "../include/httplib.h"
#include "../src/BookingManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace httplib;

BookingManager manager;
vector<string> rooms = {
    "A1","A2","A3",
    "B1","B2","B3",
    "C1","C2","C3",
    "D1","D2","D3",
    "E1","E2","E3"
};
vector<string> booked;

string readFile(const string& path) {
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    Server svr;

    // Serve index.html
    svr.Get("/", [](const Request&, Response& res) {
        string html = readFile("index.html");  
        res.set_content(html, "text/html");
    });

    // Serve static files 
    svr.Get(R"(/(.*\.js))", [](const Request& req, Response& res) {
        string js = readFile(req.path.substr(1));
        res.set_content(js, "application/javascript");
    });

    // API endpoint for booking/cancel/get_bookings
    svr.Post("/api", [](const Request& req, Response& res) {
        try {
            auto requestJson = nlohmann::json::parse(req.body);
            auto responseJson = manager.processJsonRequest(requestJson, rooms, booked);
            res.set_content(responseJson.dump(), "application/json");
        } catch (const std::exception& e) {
            nlohmann::json error;
            error["success"] = false;
            error["error"] = e.what();
            res.set_content(error.dump(), "application/json");
        }
    });

    cout << "Server started at http://localhost:8080\n";
    svr.listen("localhost", 8080);

    return 0;
}
