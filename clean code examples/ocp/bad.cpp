#include <iostream>
#include <string>
#include <vector>

using namespace std;

// XMLDocument class representing an XML document
class XMLDocument {
private:
    string xmlContent;

public:
    XMLDocument(const string& xmlContent) : xmlContent(xmlContent) {}

    string format() const {
        // Perform XML formatting logic
        return "Formatted XML: " + xmlContent;
    }
};

// JSONDocument class representing a JSON document
class JSONDocument {
private:
    string jsonContent;

public:
    JSONDocument(const string& jsonContent) : jsonContent(jsonContent) {}

    string format() const {
        // Perform JSON formatting logic
        return "Formatted JSON: " + jsonContent;
    }
};

// YAMLDocument class representing a YAML document
class YAMLDocument {
private:
    string yamlContent;

public:
    YAMLDocument(const string& yamlContent) : yamlContent(yamlContent) {}

    string format() const {
        // Perform YAML formatting logic
        return "Formatted YAML: " + yamlContent;
    }
};

// DocumentFormatter class to format documents
class DocumentFormatter {
public:
    // Violation of OCP: Directly handling each document type
    static string formatXMLDocument(const XMLDocument& xmlDocument) {
        return xmlDocument.format();
    }

    static string formatJSONDocument(const JSONDocument& jsonDocument) {
        return jsonDocument.format();
    }

    static string formatYAMLDocument(const YAMLDocument& yamlDocument) {
        return yamlDocument.format();
    }
};

int main() {
    XMLDocument xmlDocument("<book><title>Harry Potter</title><author>J.K. Rowling</author></book>");
    JSONDocument jsonDocument("{\"book\": {\"title\": \"Harry Potter\", \"author\": \"J.K. Rowling\"}}");
    YAMLDocument yamlDocument("book:\n  title: Harry Potter\n  author: J.K. Rowling");

    cout << DocumentFormatter::formatXMLDocument(xmlDocument) << endl;
    cout << DocumentFormatter::formatJSONDocument(jsonDocument) << endl;
    cout << DocumentFormatter::formatYAMLDocument(yamlDocument) << endl;

    return 0;
}
