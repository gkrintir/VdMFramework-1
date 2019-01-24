void xsecs_PCC()
{
//=========Macro generated from canvas: can/
//=========  (Fri Dec 15 00:01:36 2017) by ROOT version5.99/05
   TCanvas *can = new TCanvas("can", "",0,0,800,600);
   can->SetHighLightColor(2);
   can->Range(-0.2867501,7.175025,7.28675,7.840578);
   can->SetFillColor(0);
   can->SetBorderMode(0);
   can->SetBorderSize(2);
   can->SetFrameBorderMode(0);
   can->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle(";Scan Pair;#sigma_{Vis} (Barn)");
   
   Double_t Graph_fx1001[6] = {
   0.8,
   1.8,
   2.8,
   3.8,
   4.8,
   5.8};
   Double_t Graph_fy1001[6] = {
   7.487141,
   7.487147,
   7.39777,
   7.404446,
   7.420866,
   7.553449};
   Double_t Graph_fex1001[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1001[6] = {
   0.0540486,
   0.06278612,
   0.05056924,
   0.05520506,
   0.06574719,
   0.0380786};
   TGraphErrors *gre = new TGraphErrors(6,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0.3,6.3);
   Graph_Graph1001->SetMinimum(7.322768);
   Graph_Graph1001->SetMaximum(7.61596);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1002[6] = {
   0.9,
   1.9,
   2.9,
   3.9,
   4.9,
   5.9};
   Double_t Graph_fy1002[6] = {
   7.519484,
   7.573999,
   7.682145,
   7.316101,
   7.484919,
   7.611104};
   Double_t Graph_fex1002[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1002[6] = {
   0.05543527,
   0.06198863,
   0.0676758,
   0.05031823,
   0.05676074,
   0.05557095};
   gre = new TGraphErrors(6,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0.4,6.4);
   Graph_Graph1002->SetMinimum(7.217378);
   Graph_Graph1002->SetMaximum(7.798225);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1003[6] = {
   1,
   2,
   3,
   4,
   5,
   6};
   Double_t Graph_fy1003[6] = {
   7.51247,
   7.422758,
   7.553575,
   7.471718,
   7.428024,
   7.578426};
   Double_t Graph_fex1003[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1003[6] = {
   0.06037334,
   0.06320956,
   0.06084316,
   0.05392744,
   0.0572043,
   0.05738493};
   gre = new TGraphErrors(6,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#00cc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0.5,6.5);
   Graph_Graph1003->SetMinimum(7.331922);
   Graph_Graph1003->SetMaximum(7.663437);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1004[6] = {
   1.1,
   2.1,
   3.1,
   4.1,
   5.1,
   6.1};
   Double_t Graph_fy1004[6] = {
   7.464163,
   7.464102,
   7.408319,
   7.403893,
   7.496508,
   7.592307};
   Double_t Graph_fex1004[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1004[6] = {
   0.0575596,
   0.07826428,
   0.05141055,
   0.05125479,
   0.07976539,
   0.0583308};
   gre = new TGraphErrors(6,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0.6,6.6);
   Graph_Graph1004->SetMinimum(7.322839);
   Graph_Graph1004->SetMaximum(7.680438);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1005[6] = {
   1.2,
   2.2,
   3.2,
   4.2,
   5.2,
   6.2};
   Double_t Graph_fy1005[6] = {
   7.472572,
   7.462664,
   7.416609,
   7.334413,
   7.5843,
   7.603946};
   Double_t Graph_fex1005[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1005[6] = {
   0.06377061,
   0.06001172,
   0.05024398,
   0.05117664,
   0.0574341,
   0.07225193};
   gre = new TGraphErrors(6,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#cc00cc");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#cc00cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0.7,6.7);
   Graph_Graph1005->SetMinimum(7.24394);
   Graph_Graph1005->SetMaximum(7.715494);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("Scan Pair");
   multigraph->GetXaxis()->SetRange(0,101);
   multigraph->GetXaxis()->SetNdivisions(7);
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#sigma_{Vis} (Barn)");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   TLatex *   tex = new TLatex(0.93,0.88,"2017  (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.88,"CMS #bf{#scale[0.75]{#it{Preliminary}}}");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.73,0.15,0.93,0.43,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.037);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","BX = 41","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 281","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 872","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00cc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 1783","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 2063","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc00cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   can->Modified();
   can->cd();
   can->SetSelected(can);
}
