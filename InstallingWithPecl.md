# Howto Install with Pecl #

## Unix ##

  1. Install [LibYAML](http://pyyaml.org/wiki/LibYAML) using your favorite method. For example on a Ubuntu machine `sudo apt-get install libyaml-dev` will get what you need.
  1. `sudo pecl install yaml-beta`
  1. Edit your php.ini settings and add "extension=yaml.so"
  1. See if it worked with `php --re yaml`

## Windows ##

Good question. Anyone want to step up and figure out how to do this?