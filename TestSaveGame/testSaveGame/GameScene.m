//
//  GameScene.m
//  testSaveGame
//
//  Created by Coody on 2016/6/4.
//  Copyright (c) 2016年 Coody. All rights reserved.
//

#import "GameScene.h"

#import "SaveFileTools.h"
#import "SaveFileToolsManager.h"
#import "RemoteNotificationFileTool.h"

@implementation GameScene

-(void)didMoveToView:(SKView *)view {
    /* Setup your scene here */
    SKLabelNode *myLabel = [SKLabelNode labelNodeWithFontNamed:@"Chalkduster"];
    
    myLabel.text = @"Touch Chek!";
    myLabel.fontSize = 45;
    myLabel.position = CGPointMake(CGRectGetMidX(self.frame),
                                   CGRectGetMidY(self.frame));
    
    [self addChild:myLabel];
    
    [[SaveFileToolsManager sharedInstance] initialFilePath:@"test/TestSaveFile"];
    [[SaveFileToolsManager sharedInstance] initialSaveFileToolsWithClassNameArray:@[@"RemoteNotificationFileTool"]
                                                                          withKey:@"fileOne"];
    
    
    
    
    [[SaveFileToolsManager sharedInstance] loadWithKey:@"fileOne"];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    NSLog(@"點擊！");
    
    RemoteNotificationFileTool *test = [[SaveFileToolsManager sharedInstance] getSaveFileToolsWithName:@"RemoteNotificationFileTool"];
    RemoteNotificationFileTool_Model *model = test.Model;
    
    model.cer = @"CoodyTest";
    model.cer_path = @"abc/1123/coody";
    model.number = -123;
    
    NSLog(@" %@ , %@" , test , model);
    
    
    [[SaveFileToolsManager sharedInstance] saveWithKey:@"fileOne"];
}

-(void)update:(CFTimeInterval)currentTime {
    /* Called before each frame is rendered */
}

@end
