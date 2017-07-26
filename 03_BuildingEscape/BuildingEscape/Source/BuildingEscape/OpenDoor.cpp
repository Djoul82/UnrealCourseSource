// Copyright Julien Salamin 2017

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Find the owning actor
	AActor* Owner = GetOwner();

	// Create a rotator
	FRotator NewRotation = FRotator(0,-45.0f,0);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);

	// Print logs
	FString DoorRotation = Owner->GetTransform().GetRotation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("Door is at %s !"), *DoorRotation);
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

