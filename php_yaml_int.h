/**
 * YAML parser and emitter PHP extension
 *
 * Copyright (c) 2007 Ryusuke SEKIYAMA. All rights reserved.
 * Copyright (c) 2009 Keynetics Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * @package     php_yaml
 * @author      Ryusuke SEKIYAMA <rsky0711@gmail.com>
 * @author      Bryan Davis <bpd@keynetics.com>
 * @copyright   2007 Ryusuke SEKIYAMA
 * @copyright   2009 Keynetics Inc
 * @license     http://www.opensource.org/licenses/mit-license.php  MIT License
 * @version     SVN: $Id$
 */


#ifndef PHP_YAML_INT_H
#define PHP_YAML_INT_H

#ifdef __cplusplus
extern "C" {
#endif

/* {{{ ext/yaml macros
 */
#define YAML_BINARY_TAG     "tag:yaml.org,2002:binary"
#define YAML_PHP_TAG        "!php/object"

/* }}} */

/* {{{ ext/yaml prototypes
 */
zval * php_yaml_read_impl (
    yaml_parser_t *parser, yaml_event_t *parent,
    zval *aliases, zval *zv, long *ndocs,
    eval_scalar_func_t eval_func, HashTable *callbacks TSRMLS_DC);

zval * php_yaml_read_partial (
    yaml_parser_t *parser, long pos, long *ndocs,
    eval_scalar_func_t eval_func, HashTable *callbacks TSRMLS_DC);

zval * php_yaml_eval_scalar (
    yaml_event_t event, HashTable *callbacks TSRMLS_DC);

zval * php_yaml_eval_scalar_with_callbacks (
    yaml_event_t event, HashTable *callbacks TSRMLS_DC);

char * php_yaml_detect_scalar_type (
    const char *value, size_t length, const yaml_event_t *event);

int php_yaml_write_impl (
    yaml_emitter_t *emitter, zval *data, yaml_encoding_t encoding TSRMLS_DC);

int php_yaml_write_to_buffer (
    void *data, unsigned char *buffer, size_t size);

/* }}} */

#if (PHP_MAJOR_VERSION > 5) || ((PHP_MAJOR_VERSION == 5) && (PHP_MINOR_VERSION >= 3))
# define IS_CALLABLE(a,b,c) zend_is_callable((a), (b), (c) TSRMLS_CC)
#else
# define IS_CALLABLE(a,b,c) zend_is_callable((a), (b), (c))
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* PHP_YAML_INT_H */

/*
 * Local variables:
 * tab-width: 2
 * c-basic-offset: 2
 * End:
 * vim600: et sw=2 ts=2 fdm=marker
 * vim<600: et sw=2 ts=2
 */
