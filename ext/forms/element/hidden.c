
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "forms/element/hidden.h"
#include "forms/element.h"
#include "forms/elementinterface.h"
#include "forms/element/helpers.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"

/**
 * Phalcon\Forms\Element\Hidden
 *
 * Component INPUT[type=hidden] for forms
 */
zend_class_entry *phalcon_forms_element_hidden_ce;

PHP_METHOD(Phalcon_Forms_Element_Hidden, __construct);
PHP_METHOD(Phalcon_Forms_Element_Hidden, render);

static const zend_function_entry phalcon_forms_element_hidden_method_entry[] = {
	PHP_ME(Phalcon_Forms_Element_Hidden, __construct, arginfo_phalcon_forms_elementinterface___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_Hidden, render, arginfo_phalcon_forms_elementinterface_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Forms\Element\Hidden initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_Hidden){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Hidden, forms_element_hidden, phalcon_forms_element_ce, phalcon_forms_element_hidden_method_entry, 0);

	zend_class_implements(phalcon_forms_element_hidden_ce, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Element\Hidden constructor
 *
 * @param string $name
 * @param array $attributes
 * @param array $options
 * @param array $optionsValues
 */
PHP_METHOD(Phalcon_Forms_Element_Hidden, __construct){

	zval *name, *attributes = NULL, *options = NULL, *options_values = NULL, *_type = NULL, type = {};

	phalcon_fetch_params(0, 1, 4, &name, &attributes, &options, &options_values, &_type);

	if (!attributes) {
		attributes = &PHALCON_GLOBAL(z_null);
	}

	if (!options) {
		options = &PHALCON_GLOBAL(z_null);
	}

	if (!options_values) {
		options_values = &PHALCON_GLOBAL(z_null);
	}

	if (!_type || PHALCON_IS_EMPTY(_type)) {
		ZVAL_STRING(&type, "hidden");
	} else {
		ZVAL_COPY_VALUE(&type, _type);
	}

	PHALCON_CALL_PARENT(NULL, phalcon_forms_element_hidden_ce, getThis(), "__construct", name, attributes, options, options_values, &type);
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Hidden, render){

	phalcon_forms_element_render_helper("hiddenfield", 0, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
