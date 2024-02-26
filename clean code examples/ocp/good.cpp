#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Document class representing XML and JSON documents
class Document {
public:
    virtual string format() const = 0;
};

// XMLDocument class representing an XML document
class XMLDocument : public Document {
private:
    string xmlContent;

public:
    XMLDocument(const string& xmlContent) : xmlContent(xmlContent) {}

    string format() const override {
        // Perform XML formatting logic
        return "Formatted XML: " + xmlContent;
    }
};

// JSONDocument class representing a JSON document
class JSONDocument : public Document {
private:
    string jsonContent;

public:
    JSONDocument(const string& jsonContent) : jsonContent(jsonContent) {}

    string format() const override {
        // Perform JSON formatting logic
        return "Formatted JSON: " + jsonContent;
    }
};

// YAMLDocument class representing a YAML document
class YAMLDocument : public Document {
private:
    string yamlContent;

public:
    YAMLDocument(const string& yamlContent) : yamlContent(yamlContent) {}

    string format() const override {
        // Perform YAML formatting logic
        return "Formatted YAML: " + yamlContent;
    }
};

// DocumentFormatter class to format documents using the Strategy Pattern
class DocumentFormatter {
public:
    static string formatDocument(const Document& document) {
        return document.format();
    }
};

int main() {
    XMLDocument xmlDocument("<book><title>Harry Potter</title><author>J.K. Rowling</author></book>");
    JSONDocument jsonDocument("{\"book\": {\"title\": \"Harry Potter\", \"author\": \"J.K. Rowling\"}}");
    YAMLDocument yamlDocument("book:\n  title: Harry Potter\n  author: J.K. Rowling");

    cout << DocumentFormatter::formatDocument(xmlDocument) << endl;
    cout << DocumentFormatter::formatDocument(jsonDocument) << endl;
    cout << DocumentFormatter::formatDocument(yamlDocument) << endl;

    return 0;
}
