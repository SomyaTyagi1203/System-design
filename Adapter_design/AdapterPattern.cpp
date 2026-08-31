#include <iostream>
#include <string>

using namespace std;

class IReports {
public:

    virtual string getJsonData(const string& data) = 0;
    virtual ~IReports() {}
};


//Adaptee Class
class XmlDataProvider {

public:
    string getXmlData(const string& data) {
        size_t sep = data.find(':');
        string name = data.substr(0, sep);
        string id = data.substr(sep+1);

        return "<user>"
               "<name>" + name + "</name>"
               "<id>"   + id   + "</id>"
               "</user>";
    }
};


class XmlProviderAdapter: public IReports {

private:
    XmlDataProvider *xmlProvider;

public:
    XmlProviderAdapter(XmlDataProvider* provider) {
        this->xmlProvider = provider;
    }

    string getJsonData(const string& data) override {
        string xml = xmlProvider->getXmlData(data);

        size_t startName = xml.find("<name>") + 6;
        size_t endName   = xml.find("</name>");
        string name      = xml.substr(startName, endName - startName);
        size_t startId = xml.find("<id>") + 4;
        size_t endId   = xml.find("</id>");
        string id      = xml.substr(startId, endId - startId);

        // 3. Build and return JSON
        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }
};

class Client {

public:
    void getReport(IReports* report, string rawData) {
        cout<< "Processed Json: " << report->getJsonData(rawData)<<endl;
    }
};


int main() {
    XmlDataProvider* xmlProv = new XmlDataProvider();

    IReports* adapter = new XmlProviderAdapter(xmlProv);

    string rawData = "Somya:24";

    Client* client = new Client();

    client->getReport(adapter, rawData);
    

    delete adapter;
    delete xmlProv;
    return 0;
}