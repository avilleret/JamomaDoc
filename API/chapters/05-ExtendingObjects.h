/** 
 	@page chapter_extendingobjects Extending Objects

	@author Jamoma, Timothy Place

	@section chapter_extendingobjects_subclassing Subclassing Objects

	The classical methodology for extending functionality in object-oriented designs is to subclass an object.
	In other words, we derive a new object that inherits all of the functionality of a parent class.
	This is also possible with Jamoma Foundation classes, though you may wish to keep a few guidelines in mind when subclassing.

	@section chapter_extendingobjects_decorating Decorating Objects

	Because the Jamoma Foundation provides a dynamic and reflective API for creating objects, we can extend objects by means other than subclassing.
	One specific way of doing this is by decorating a class.
	For example, let us assume that we have a bandpass filter for processing audio.
	Further, this object understands how to control its center frequency using an attribute specified in Hertz.
	What are we to do if we want to communicate with the object using the Bark scale?

	One option is to write a conversion routine and always call that routine to convert the value, then send a message the filter.
	A second option is subclass the filter, creating another filter which has the required attribute specified using Barks.
	A third option is to decorate the existing filter.

 	@subsection chapter_extendingobjects_decorating_twokinds Two Kinds of Decoration

	The Decorator Pattern, in the classical sense, is where an object is passed a second object and this second object uses the first object to help get its work done <b>{gang of four, page?}</b>.  However, the work done by the class is typically fixed and does not change.  For example, an HTML rendering engine may have the ability to take a decorator object that will provide a custom footer for a page, but the page structure is fixed.  Another example is in writing tests <b>{shalloway and trott, page 307}</b>.

	Another kind of decoration is to actually expand a class by adding messages and attributes to an instance after it has been created.
	While the former means of passing in a decorator class for a pre-determined purpose is useful in some contexts in TTBlue, this later means of creating entirely new functionality is what we are looking to do for solving the problem defined in @ref chapter_extendingobjects_decorating.

 	@subsection chapter_extendingobjects_decorating_example An Example


 	by adding a new attribute to it at runtime.

	...

	@section chapter_extendingobjects_observer Keeping An Eye On Objects

	If you are working with objects, extending them, or creating a graph of connected objects, you will likely need to keep tabs on some objects or certain aspects of those objects.  TTBlue provides an easy way to monitor the state of objects using an Observer strategy <b>{gang of four, page?}</b>.

	In the example below we have an object and two observers.  
	The observers provide a way to view any changes to the state of our object.

	@code{.cpp}
	TTObjectPtr	ourObject;
	TTObjectPtr	firstView;
	TTObjectPtr	secondView;
	@endcode

*/