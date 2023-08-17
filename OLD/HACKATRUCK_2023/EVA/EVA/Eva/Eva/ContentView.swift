//
//  ContentView.swift
//  Eva
//
//  Created by Student05 on 01/06/23.
//

import SwiftUI

struct ContentView: View {
    
    var body: some View {
        
        TabView{
            
            Perfil()
            .tabItem{
                Label("Perfil", systemImage: "person.crop.circle")
            }
            
            Feed()
            .tabItem{
                Label("Feed", systemImage: "newspaper")
            }
            
            Configuracoes()
            .tabItem{
                Label("Configuração", systemImage: "gearshape.fill")
            }
            
        }.padding(.bottom, 5.0).accentColor(Color("Purple"))
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
