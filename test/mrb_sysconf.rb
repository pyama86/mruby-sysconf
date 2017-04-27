##
## Sysconf Test
##

assert("Sysconf#get") do
  t = Sysconf._SC_CLK_TCK
  assert_equal(100, t)
end
