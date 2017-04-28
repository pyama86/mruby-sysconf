##
## Sysconf Test
##

assert("Sysconf#get") do
  assert_equal(100, Sysconf::SC_CLK_TCK)
end
