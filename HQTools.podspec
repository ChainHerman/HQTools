Pod::Spec.new do |s|
  s.name         = "HQTools"
  s.version      = "1.0.1"
  s.summary      = "HQ工具类"
  s.description  = <<-DESC
                   DESC
  s.homepage     = "https://github.com/HermanForHeQian/HQTools.git"
  s.license      = "MIT"
  s.author             = { "heqian" => "1902046492@qq.com" }
  s.source       = { :git => "https://github.com/HermanForHeQian/HQTools.git", :tag => "#{s.version}" }
  s.source_files  = "HQTools", "HQTools/HQTools.framework/Header/*.{h}"
###  s.exclude_files = "Classes/Exclude"

end
