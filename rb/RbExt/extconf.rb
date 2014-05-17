# load mkmf to make makefile for Ruby extensions

require 'mkmf'

extn_name = 'RubExt'

# destination

dir_config(extn_name)

create_makefile(extn_name)

