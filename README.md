# mruby-sysconf   [![Build Status](https://travis-ci.org/pyama86/mruby-sysconf.svg?branch=master)](https://travis-ci.org/pyama86/mruby-sysconf)
Sysconf class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'pyama86/mruby-sysconf'
end
```
## example
```ruby
puts Sysconf::SC_CLK_TC
```

## License
under the MIT License:
- see LICENSE file
