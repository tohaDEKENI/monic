#include <iostream>
#include <sstream>
#include <iomanip>
#include <httplib.h>
#include "monic.h"

int main() {
    httplib::Server server;

    server.Get("/", [](auto & /*req*/, auto &res){
        // Récupérer toutes les valeurs à chaque requête
        float cpu = get_cpu_usage();
        float ram = get_ram_usage();
        LoadAverage avg = get_average();
        Uptime up = get_uptime();
        RamSwap mem = get_ram_and_swap();

        // Construire le JSON avec 2 décimales
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << "{";
        oss << "\"cpu\":" << cpu << ",";
        oss << "\"ram\":" << ram << ",";
        oss << "\"load\":{"
            << "\"1m\":" << avg.one_min << ","
            << "\"5m\":" << avg.five_min << ","
            << "\"15m\":" << avg.fifteen_min << "},";
        oss << "\"uptime\":{"
            << "\"h\":" << up.hours << ","
            << "\"m\":" << up.min << ","
            << "\"s\":" << up.sec << "},";
        oss << "\"memory\":{"
            << "\"ram_total\":" << mem.total_ram << ","
            << "\"ram_used\":" << mem.ram_used << ","
            << "\"swap_total\":" << mem.swap_total << ","
            << "\"swap_used\":" << mem.swap_used
            << "}";
        oss << "}";

        std::string json = oss.str();
        std::cout << "JSON envoyé: " << json << std::endl;
        res.set_header("Access-Control-Allow-Origin", "*");

        res.set_content(json, "application/json");
    });

    std::cout << "Serveur MoniC lancé sur http://localhost:8080\n";
    server.listen("0.0.0.0", 8080);

    return 0;
}
