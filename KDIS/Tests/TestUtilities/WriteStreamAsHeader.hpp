#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "./KDIS/KDataStream.h"
#include "./KDIS/KDefines.h"


void WriteStreamAsHeader(std::string name, KDIS::KDataStream& stream) {
    std::ofstream out;
    std::string filename = "TestData/" + name + ".hpp";

    out.open(filename.c_str(), std::ofstream::trunc);
    if(!out.is_open()) {
        std::cerr << "error opening file: " << filename << std::endl;
        throw std::runtime_error("can't open file");
    }
    out << std::hex << std::setfill('0') << std::setw(2);
    out << "#pragma once\n\n";
    out << "#include \"KDIS/KDefines.h\"\n\n";
    out << "namespace " << name << " {\n\n";
    out << "static const KDIS::KUINT16 size = " << stream.GetBufferSize() << ";\n";
    out << "static const KDIS::KUOCTET buffer[] = {\n    ";

    const int BUFFER_SIZE = stream.GetBufferSize();
    const KDIS::KOCTET* BUFFER_PTR = stream.GetBufferPtr();
    for(int i = 0; i < BUFFER_SIZE - 1; ++i) {
        out << "0x" << std::setw(2) <<
            // cast so it doesn't print as ASCII
            // mask so it doesn't sign extend
            (static_cast<KDIS::KUINT16>(BUFFER_PTR[i]) & 0xFF)
            << ", ";

        static const int BYTES_BEFORE_NEWLINE = 8;
        if((i + 1) % BYTES_BEFORE_NEWLINE == 0) {
            out << "\n    ";
        }
    }
    // write the last byte
    out <<  "0x" << std::setw(2) <<
            // cast so it doesn't print as ASCII
            // mask so it doesn't sign extend
            (static_cast<KDIS::KUINT16>(BUFFER_PTR[BUFFER_SIZE - 1]) & 0xFF)
            << "\n};\n\n}\n";
    out.close();
}
