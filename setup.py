from distutils.core import setup, Extension

gost_hash_module = Extension('gost_hash',
                                 sources = ['gostmodule.c',
                                            'gosthash.c',
                                            
                                            'sha3/gost.c'],
                                            
                               include_dirs=['.', './sha3'])

setup (name = 'gost_hash',
       version = '1.4',
       description = 'Binding for Gost proof of work hashing.',
       ext_modules = [gost_hash_module])
