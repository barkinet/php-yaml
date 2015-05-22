The Yaml PHP Extension provides a wrapper to the LibYAML library.

It gives the user the ability to parse YAML document streams into PHP
constructs and emit PHP constructs as valid YAML 1.1 documents.

  * For more information about LibYAML see http://pyyaml.org/wiki/LibYAML.
  * For more information about YAML see http://yaml.org/

## Key Features ##
  * [LibYAML parser](http://pyyaml.org/wiki/LibYAML) much faster than any pure PHP solution
  * Supports YAML 1.1 standard
  * Supports '<<' [Merge Key](http://yaml.org/type/merge.html) in mappings
  * Parser supports user-defined callbacks for custom yaml tag handling
  * Can extract one or all documents from a stream of valid YAML text

## Installation ##

Php-yaml can be installed [using PHP's PECL package manager](InstallingWithPecl.md).

## Use ##

See the [extension documentation](http://php.net/yaml) for (mostly) complete details on using the library.

### Example ###
```
<?php
$addr = array(
    "given" => "Chris",
    "family"=> "Dumars",
    "address"=> array(
        "lines"=> "458 Walkman Dr.
        Suite #292",
        "city"=> "Royal Oak",
        "state"=> "MI",
        "postal"=> 48046,
      ),
  );
$invoice = array (
    "invoice"=> 34843,
    "date"=> "2001-01-23",
    "bill-to"=> $addr,
    "ship-to"=> $addr,
    "product"=> array(
        array(
            "sku"=> "BL394D",
            "quantity"=> 4,
            "description"=> "Basketball",
            "price"=> 450,
          ),
        array(
            "sku"=> "BL4438H",
            "quantity"=> 1,
            "description"=> "Super Hoop",
            "price"=> 2392,
          ),
      ),
    "tax"=> 251.42,
    "total"=> 4443.52,
    "comments"=> "Late afternoon is best. Backup contact is Nancy Billsmer @ 338-4338.",
    );

// generate a YAML representation of the invoice
$yaml = yaml_emit($invoice);
var_dump($yaml);

// convert the YAML back into a PHP variable
$parsed = yaml_parse($yaml);

// check that roundtrip conversion produced an equivalent structure
var_dump($parsed == $invoice);
```


&lt;wiki:gadget url="http://www.ohloh.net/p/479573/widgets/project\_basic\_stats.xml" height="220" border="0"/&gt;