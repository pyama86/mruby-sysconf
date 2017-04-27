class Sysconf
  class << self
    def method_missing(method_name, *args, &block)
      self.get(method_name.to_s)
    end
  end
end
