#ifndef config_h
#define config_h

class Config
{
private:
    std::string configpath;
    picojson::value jsonValue;

public:
    Config(std::string configPath);
    picojson::object &read();
};

Config::Config(std::string configPath)
{
    this->configpath = configPath;
}

picojson::object& Config::read()
{
    std::ifstream ifs(this->configpath, std::ios::in);
    if (ifs.fail())
    {
        std::cerr << "failed to read " << this->configpath << std::endl;
        return this->jsonValue.get<picojson::object>();
    }

    const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    const std::string err = picojson::parse(this->jsonValue, json);
    if (err.empty() == false)
    {
        std::cerr << err << std::endl;
        return this->jsonValue.get<picojson::object>();
    }

    return this->jsonValue.get<picojson::object>();
}
#endif