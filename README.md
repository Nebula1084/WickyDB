# WickyDB #
a mini SQL database for our course.
## CatalogManager ##
This class is used to manage the catalog information like `table`, `column` and `type`. And here is its member function.<br/>
`Table createTable(string name, map<string, string> atrs);`<br/>
we pass two arguments into this function, which are table name and column defination
respectively. Especially, the key-value-map's `key` is `attribute name` and it's `value` is
`attribute type`. <br/>
`void dropTable(Table* table)` <br/>
`Table getTable(string name)` <br/>