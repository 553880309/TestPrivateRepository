//
//  MSViewController.m
//  TestPrivateRepo
//
//  Created by 553880309 on 03/21/2019.
//  Copyright (c) 2019 553880309. All rights reserved.
//

#import "MSViewController.h"
#import <RongIMLib/RongIMLib.h>
#import <WUBAPush.h>
@interface MSViewController ()

@end

@implementation MSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [[RCIMClient sharedRCIMClient] registerMessageType:[NSObject class]];
//    [[WIMClient sharedClient] initSDKWith:nil];
    [WUBAPush registerDeviceToken:nil];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
