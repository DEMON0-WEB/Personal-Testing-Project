// Fill out your copyright notice in the Description page of Project Settings.


#include "InterplatingTo.h"

// Sets default values for this component's properties
UInterplatingTo::UInterplatingTo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	parent = GetOwner();
	// ...
}


// Called when the game starts
void UInterplatingTo::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInterplatingTo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (WaitTime > 0) {
		WaitTime -= DeltaTime;
		return;
	}
	if (!TargetActor) {
		return;
	}

	parent->SetActorLocation(FMath::VInterpTo(parent->GetActorLocation(), TargetActor->GetActorLocation(), DeltaTime, MoveSpeed));

	FRotator NewRotation = TargetActor->GetActorRotation() + 2 * DeltaTime;
	TargetActor->SetActorRotation(NewRotation);
	// ...
}

