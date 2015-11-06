#<span id="title">Class Scehame</span> 
It stores and manages the information of a table  
`friend class CatalogManager`

##Examples
```
Schema sch("student");
sch.getName();
sch.addAttribute("name", Schema::CHAR);
sch.setPrimaryKey("name");
sch.addIndex("indexOnName", "name");
sch.getIndex("name");
sch.deleteIndex("indexOnName");
```

---
##Field Summary
###Private Field
|Type|Name|Description|  
|:---|:---|:----------|  
|std::string |tableName |the name of the table  
|std::vector `<std::string>` |attrNames |the list of the attribute names  
|std::map`<std::string, Attribute>` |attributes|the map stores the attributes, the key is the attribute name, and the value is the attribute
|std::map`<std::string, std::string>` |indecies |the map stores the indecis, the key is the index name, and the value is the attribute has the index
|std::string |primaryKey |the primary key of he table, it's default value is "NULL"
###Static Field
|Type|Name|Description|  
|:---|:---|:----------|  
|const static std::string |INT |represent the int type of data, the value is "INT"
|const static std::string |CHAR |represent the char type of data, the value is "CHAR"
|const static std::string |FLOAT |represent the float type of data, the value is "FLOAT"
|const static int |INT_LENGTH |length of int, the value is 4
|const static int |FLOAT_LENGTH |length of float, the value is 8
|const static std::string |NOINDEX |represent no index, the value is "NOINDEX"
|const static std::string |BTREE |represent B+ Tree index, the value is "BTREE"
|const static std::string |UNIQUE |indicate that an attribute is unique, the value is "UNIQUE"
|const static std::string |DUPLIC |indicate that an attribute is not unique, the value is "DUPLIC"


---
##Method Summary
| Return | Method name |Describetion|
|:-------|:------------|:-----------|
|static Schema |createSchema(std::string schString) |construct the schema from a string, it's `private`
|std::string |getName() |get the table name
|std::string |toString() |convert the schema to a string for the convenience of print and store
|void |addAttribute(std::string attrName, std::string type) |add a new attribute to schema
|bool |isAttrExists(std::string attrName) |return true if the schema has the attribute
|bool |isIndexExists(std::string indexName) |return true if the schema has the index
|std::string |getIndex(std::string attrName) |return the index on the attribute
|void |addIndex(std::string indexName, std::string attrName) |add index to the attribute
|void |deleteIndex(std::string indexName) |delete the index form the attribute
|void |setPrimaryKey(std::string attrName) |set an attribute as the primary key of the table
|std::string |getPrimaryKey() |return the primary key
|void |setUnique(std::string attrName) |set the attribute to unique
|bool |isUnique(std::string attrName) |return true if the attribute is unique
|void |setType(std::string attrName, std::string type) |set the type of an attribute
|std::string |getType(std::string attrName) |return the type of the attribute
|void |setLength(std::string attrName, int length) |set the length of an attribute
|int |getLength(std::string attrName) |return the length of the attribute
|Attribute |getAttribute(std::string attrName) |find an attribute by it's name
|std::vector<std::string> |getAttributes() |return a list of attribute names
|void |copyAttributes(std::vector<Attribute>& container) |copy the attributes to a vector
|static std::string |intToString(int i) |used to convert an int to a string
|static int |stringToInt(std::string str) |used to convert a string to an int
|static std::vector<std::string> |Split(std::string str,std::string pattern) |split a string and store the result into a vector


---
>##Method Detials
>**Constructor:** `Schema`(std::string tableName);
>>Initialize a schema with the table name, set the primary key to "NULL"  
 **Parameters:**  
 *tableName-* The name of the table to create   

>static Schema `createSchema`(std::string schString);
>>Construct a schema instance from a string, it's only used when recover the schema from a file, and it's a `private` method  
 **Paremeters:**  
 *schSring-* the string contains the full information of a schema,
 and it's in perticular format  
 **Returns:**  
 A Schema object  

>std::string `getName`();
>>Get the table name  
 **Returns:**  
 A string which is the table name  
 
>std::string `toString`();
>>Convert the object to a string, it will be used to store in file or print to console  
 **Returns:**  
 A string contains the full information of the schema  
 
>void `addAttribute`(std::string attrName, std::string type);
>>Add a new attribute to the schema with the attribute name and type, the default value of attribute is `length=20, index=NOINDEX, unique=DUPLIC`  
 **Parameters:**  
 *attrName-* name of the attribute to be added  
 *type-* type of the attribute to be added  
 **Throws:**  
 *runtime_error-* if the attribute already exist  
 
>bool `isAttrExists`(std::string attrName);
>>**Parameters:**  
 *attrName-* the atribute name to be tested  
 **Returns:**  
 `true` if the attribute exists, `false` otherwise  
 
>bool `isIndexExists`(std::string indexName);
>>Returns `true` if the certain index exists, `false` otherwise  
 **Parameters:**  
 *indexName-* the index name to be tested  
 **Returns:**  
 `true` if the index exists, `false` otherwise  

>std::string `getIndex`(std::string attrName);
>>Get the index name of attribute, if there is no index on the attribute, returns `NOINDEX`  
 **Parameters:**  
 *attrName-* the name of the attribute to get index  
 **Returns:**  
 a string, eithor the name of the index or `NOINDEX`  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  
 
>void `addIndex`(std::string indexName, std::string attrName);
>>Add a new index to the schema  
 **Parameters:**  
 *indexName-* the name of the index to be added  
 *attrName-* the name of the attribute which index add to  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist, or the index already exist, or the attribute already had an index  
 
>void `deleteIndex`(std::string indexName);
>>Delete the index by it's name  
 **Parameters:**  
 *indexName-* the name of the index to be deleted  
 **Throws:**  
 *runtime_error-* if the index doesn't exist  
 
>void `setPrimaryKey`(std::string attrName);
>>Set the attribute as the primary key  
 **Parameters:**  
 *attrName-* the name of the attribute to be set as the primary key  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  

>std::string `getPrimaryKey`();
>>Return the primary key of the schema  
 **Returns:**  
 A string, eithor the name of the attribute which is the primary key, or "NULL" if doesn't have primary key  
 
>void `setUnique`(std::string attrName);
>>Set the attribute to be unique  
 **Parameters:**  
 *attrName-* the name of the attribute to set   
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  
 
>bool `isUnique`(std::string attrName);
>>Reeturns `true` if the attribute is unique, `false` otherwise  
 **Parameters:**  
 *attrName-* the name of the attribute to test  
 **Returns:**  
`true` if the attribute is unique, `false` otherwise  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  
 
>void `setType`(std::string attrName, std::string type);
>>Change the attribute type  
 **Parameters:**  
 *attrName-* the name of the attribute to change  
 *type-* the type the attribute changed to  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  

>std::string `getType`(std::string attrName);  
>>Returns the attribute type, it can be `INT, CHAR, FLOAT`  
 **Parameters:**  
 *attrName-* the name of the attribute to get type  
 **Returns:**  
 A string which is the attribute's type  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  
 
>void `setLength`(std::string attrName, int length);
>>Change the attribute length  
 **Parameters:**  
 *attrName-* the name of the attribute to change  
 *length-* the new length the attribute changed to  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  
 
>int `getLength`(std::string attrName);  
>>Returns the attribute length  
 **Parameters:**   
 *attrName-* the name of the attribute to get length  
 **Returns:**  
 An integer which is the attribute's length  
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  
 
>Attribute `getAttribute`(std::string attrName);
>>Find the attribute by it's name, and return  
 **Parameters:**  
 *attrName-* the name of the attribute to return  
 **Returns:**  
 An Attribute object   
 **Throws:**  
 *runtime_error-* if the attribute doesn't exist  

>std::`vector<std::string>` `getAttributes`();
>>Get the name list of all the attributes in schema  
 **Returns:**  
 A vector contains the attribute names, and are sorted in the same sequence as they were added   

>void `copyAttributes`(std::`vector<Attribute>`& container);  
>>Copy all the attributes in the schema  
 **Parameters:**  
 *container-* a reference of an Attribute vector which receives the attributes  

>static std::string `intToString`(int i);
>>Convert an int to a string  
 **Parameters:**  
 *i-* the int to be converted  
 **Returns:**  
 An string consists of integer(s)  
  
>static int `stringToInt`(std::string str);  
>>Convert a string to an int  
 **Parameters:**  
 *str-* a string consists of integer(s)  
 **Returns:**  
 An int convert from the string  

>static std::`vector<std::string>` `Split`(std::string str,std::string pattern);
>>Split the target string by the pattern, and store the result string into a vector by their sequence in the original string  
 **Parameters:**  
 *str-* the origin string  
 *pattern-* the string used to split the origin string  
 **Returns:**  
 An vector contains the result strings  
 

