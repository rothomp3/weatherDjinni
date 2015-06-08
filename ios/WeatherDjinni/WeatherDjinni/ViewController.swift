//
//  ViewController.swift
//  WeatherDjinni
//
//  Created by Robert Thompson on 6/4/15.
//  Copyright (c) 2015 WillowTree Apps. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class ViewController: UIViewController, UISearchBarDelegate, MKMapViewDelegate {
    @IBOutlet weak var searchBar: UISearchBar!
    @IBOutlet weak var mapView: MKMapView! {
        didSet {
            let recognizer = UITapGestureRecognizer(target: self, action: Selector("mapTapped:"))
            mapView.addGestureRecognizer(recognizer)
        }
    }
    
    var weatherController: MTWeatherController!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let networkController = NetworkControllerImpl()
        networkController.forecastComplete = self.receiveForecast
        
        weatherController = MTWeatherController.createWithNetworkController(networkController)
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func searchBarSearchButtonClicked(searchBar: UISearchBar) {
        let geocoder = CLGeocoder()
        
        geocoder.geocodeAddressString(searchBar.text, completionHandler: { [weak self]
            (placemarks: [AnyObject]!, error: NSError?) -> Void in
            if let placemark = placemarks.first as? CLPlacemark
            {
                let span = MKCoordinateSpan(latitudeDelta: 0.3, longitudeDelta: 0.3)
                let region = self?.mapView.regionThatFits(MKCoordinateRegion(center: placemark.location.coordinate, span: span))
                self?.mapView.setRegion(region!, animated: true)
                
                self?.mapView.addAnnotation(MKPlacemark(placemark: placemark))
            }
            else if let error = error
            {
                
            }
            
            searchBar.resignFirstResponder()
        })
    }
    
    func mapView(mapView: MKMapView!, didSelectAnnotationView view: MKAnnotationView!) {
        if let placemark = view.annotation as? MKPlacemark
        {
            self.processPlacemark(placemark)
        }
        
        self.mapView.deselectAnnotation(view.annotation, animated: false)
    }
    
    @objc dynamic func mapTapped(recognizer: UITapGestureRecognizer) -> Void
    {
        let location = self.mapView.convertPoint(recognizer.locationInView(self.mapView), toCoordinateFromView: self.mapView)
        
        let geocoder = CLGeocoder()
        geocoder.reverseGeocodeLocation(CLLocation(latitude: location.latitude, longitude: location.longitude), completionHandler: { (placemarks: [AnyObject]?, error: NSError?) -> Void in
            if let placemark = placemarks?.first as? CLPlacemark where placemark.name != nil && placemark.locality != nil && placemark.administrativeArea != nil && placemark.postalCode != nil && placemark.country != nil
            {
                self.searchBar.text = placemark.name + " " + placemark.locality + ", " + placemark.administrativeArea + " " + placemark.postalCode + " " + placemark.country
                self.mapView.addAnnotation(MKPlacemark(placemark: placemark))
                self.processPlacemark(placemark)
            }
        })
    }
    
    private func processPlacemark(placemark: CLPlacemark)
    {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)) {
            self.weatherController.forecast(placemark.location.coordinate.latitude, longitude: placemark.location.coordinate.longitude)
        }
    }
    
    private func receiveForecast(forecast: MTForecast) -> Void
    {
        dispatch_async(dispatch_get_main_queue()) {
            let controller = UIAlertController(title: "Current Temperature", message: "\(forecast.currently.temperature!)ºF", preferredStyle: UIAlertControllerStyle.Alert)
            controller.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Cancel, handler: nil))
            
            self.presentViewController(controller, animated: true, completion: nil)
        }
    }
}

@objc class NetworkControllerImpl : NSObject, MTNetworkController
{
    typealias forecastCompletionBlock = (result: MTForecast) -> Void
    
    var forecastComplete: forecastCompletionBlock?
    
    func get(URI: String, controller: MTWeatherController?) {
        let session = NSURLSession.sharedSession()
        if let requestURL = NSURL(string: URI)
        {
            let dataTask = session.dataTaskWithURL(requestURL) {
                (data: NSData?, response: NSURLResponse?, error: NSError?) -> Void in
                if error == nil
                {
                    if let data = data
                    {
                        controller?.receiveData(data)
                    }
                }
            }
            
            dataTask.resume()
        }
    }
    
    func post(URI: String, body: NSData) -> NSData {
        return NSData()
    }
    
    func callbackNative(result: MTForecast) {
        forecastComplete?(result: result)
    }
}