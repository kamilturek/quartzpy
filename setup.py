from distutils.core import setup, Extension

module1 = Extension(
    'quartz',
    sources=['quartzmodule.c'],
    extra_link_args=['-framework', 'ApplicationServices'],
)

setup(
    name='Quartz',
    version='0.1',
    description='This is a demo package',
    ext_modules=[module1],
)
