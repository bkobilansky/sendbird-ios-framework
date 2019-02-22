Pod::Spec.new do |s|
  s.name         = "SendBirdSDK"
  s.version      = "3.0.131"
  s.summary      = "SendBird iOS Framework"
  s.description  = "Messaging and Chat API for Mobile Apps and Websites"
  s.homepage     = "https://sendbird.com"
  s.license      = "Commercial"
  s.authors      = { "Jed Gyeong" => "jed.gyeong@sendbird.com", "Young Hwang" => "young.hwang@sendbird.com" }
  s.source       = { :git => "https://github.com/smilefam/sendbird-ios-framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "8.0"
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'SendBirdSDK.framework'
  s.ios.frameworks = ["UIKit", "QuartzCore", "CFNetwork", "Security", "Foundation", "MobileCoreServices", "CoreGraphics", "SystemConfiguration", "CoreFoundation"]
  s.ios.library   = "icucore"
end
