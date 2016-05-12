//
//  AppDelegate.h
//  ZFB0509
//
//  Created by FanLang on 16/5/9.
//  Copyright © 2016年 FanLang. All rights reserved.
//

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/


/**************************支付宝配置流程******************************/

// 1.去官网下载SDk 和 demo示例
// 2. 创建工程把下载SDK中的 AlipaySDK.bundle 和 AlipaySDK.framework 导入工程
// 3. 这时候编译可能有40多个错误，这是因为没有添加依赖库, 添加依赖库 参照“SDK依赖库.png”
// 4. 再编译可能出现两个错误, 如下， 这种情况 把demo中AlipaySDK.bundle 和 AlipaySDK.framework
//      两个库粘贴到工程中替换即可
/**
 Undefined symbols for architecture x86_64:
 "_OBJC_CLASS_$_UTDevice", referenced from:
 objc-class-ref in AlipaySDK
 ld: symbol(s) not found for architecture x86_64
 clang: error: linker command failed with exit code 1 (use -v to see invocation)
 
 */


// 5. 把demo中 Util, openssl, Order.h, Order.m, 4个文件导入工程 编译可能有12错误
//  (1) 有关 Base64 的错误 只需要创建一个pch 文件 或者直接demo中的拖动工程中， 其中内容可以具体可参考 AliSDKDemo-Prefix.pch
//  (2) 再编译可能出现一个错误  ‘openssl/asn1.h’ file not found, 这是在工程中没有找到opnssl文件的路径
/**
  解决方法：
  （1）点击openssl文件 show in finder 找到路径，例如: /Users/文件名/文件名/工程名/openssl（中间文件名的个数根据自己的路径而定， 不是说我写了两个，就是两个，此处只是举了一个例子）
  （2）点击工程 在 Build Setting 下搜索 Search Paths, 找到 Header Search Paths 和 Library Search Paths 两个选项
  （3）点击 Header Search Paths 添加  $(SRCROOT)/Users/文件名/文件名/工程名
   (4) 点击 Library Search Paths 添加 $(inherited) 和 $(PROJECT_DIR)/Users/文件名/文件名/工程名
 
  6. 编译后会有13个错误 如图 13个错误.png， 参考链接：http://www.cocoachina.com/bbs/read.php?tid=336168
     把demo 中 libcrypto.a 和 libssl.a 拖到工程中
  7. 到此 支付宝配置 已经完成  参考 Appdelegate.m  ViewController.m

 
 */

/************ 如配置过程有其他问题可以添加QQ：1336263866 *************/
/**********也可以提交问题到邮箱：leisong1991@126.com  ******************/


/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/



#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;


@end

