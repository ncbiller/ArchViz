// Fill out your copyright notice in the Description page of Project Settings.

#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"


// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(FName("VRCamera"));
	Camera->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//UE_LOG(LogTemp, Warning, TEXT("look vector %s, "), *ForwardVector.ToCompactString());
}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AVRCharacter::MoveRight);
}

void AVRCharacter::MoveForward(float val)
{
	//UE_LOG(LogTemp, Warning, TEXT("move Forward %f"), val);
	ForwardVector = Camera->GetForwardVector();
	FVector NewLocation = GetActorLocation();
	NewLocation += ForwardVector * val;
	SetActorLocation(NewLocation);
}

void AVRCharacter::MoveRight(float val)
{
	//UE_LOG(LogTemp, Warning, TEXT("move Forward %f"), val);
	ForwardVector = Camera->GetRightVector();
	FVector NewLocation = GetActorLocation();
	NewLocation += ForwardVector * val;
	SetActorLocation(NewLocation);
}

